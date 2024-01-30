#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 二叉树
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// 初始化二叉树
TreeNode* initTree(vector<int>& nums)
{
	if (nums.empty()) return nullptr;

	// 保存节点数组, 若 nums[i] == -1, 则保存空指针
	vector<TreeNode*> nodes;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == -1) nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(nums[i]));
	}

	// 构造二叉树, 父节点下标 i, 左孩子下标 2*i+1, 右孩子下标 2*i+2
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i] == nullptr) continue;
		int leftIdx = 2 * i + 1;
		int rightIdx = 2 * i + 2;

		if (leftIdx < nodes.size()) {
			nodes[i]->left = nodes[leftIdx];
		}
		if (rightIdx < nodes.size()) {
			nodes[i]->right = nodes[rightIdx];
		}
	}
	return nodes[0];
}

/*
	尽可能将摄像头放在叶子节点的父节点, 并且隔两层放置摄像头

	规定以下节点状态:
	状态 0 表示无覆盖, 通常是叶子节点、有覆盖的父节点
	状态 1 表示有摄像头, 通常是无覆盖的父节点
	状态 2 表示有覆盖, 通常是摄像头的父节点
*/

// 更新二叉树的节点状态
int update(TreeNode* cur)
{
	// 保证叶子节点是无覆盖状态
	if (cur == nullptr) return 2;

	int leftValue = update(cur->left);
	int rightValue = update(cur->right);

	// 情况 1: 若左右孩子均为有覆盖, 则当前节点为无覆盖
	if (leftValue == 2 && rightValue == 2) {
		cur->val = 0;
		return 0;
	}
	// 情况 2: 若左右孩子存在一个是无覆盖, 则当前节点为摄像头 (该情况优先于情况 3)
	else if (leftValue == 0 || rightValue == 0) {
		cur->val = 1;
		return 1;
	}
	// 情况 3: 若左右孩子存在一个有摄像头, 则当前节点为有覆盖
	else if (leftValue == 1 || rightValue == 1) {
		cur->val = 2;
		return 2;
	}

	return -1;
}


// 统计摄像头数量
void traversal(TreeNode* cur, int& ans)
{
	if (cur == nullptr) return;
	if (cur->val == 1) ans += 1;
	traversal(cur->left, ans);
	traversal(cur->right, ans);
}


int minCameraCover(TreeNode* root)
{
	int ans = 0;
	if (update(root) == 0) ans += 1;  // 情况 4: 根节点为无覆盖, 在根节点多加一个摄像头

	traversal(root, ans);
	return ans;
}


int main()
{
	vector<int> nums1 = {0, 0, -1, 0, 0};
	TreeNode* root1 = initTree(nums1);
	cout << minCameraCover(root1) << endl;

	vector<int> nums2 = {0, 0, -1, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0};
	TreeNode* root2 = initTree(nums2);
	cout << minCameraCover(root2) << endl;

	return 0;
}