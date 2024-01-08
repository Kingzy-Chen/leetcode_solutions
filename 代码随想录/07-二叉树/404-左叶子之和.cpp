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


void traversal(TreeNode* cur, bool isLeft, int& ans)
{
	// 使用 isLeft 标志判断是否为左叶子节点
	if (cur->left == nullptr && cur->right == nullptr && isLeft) {
		ans += cur->val;
	}
	if (cur->left) traversal(cur->left, true, ans);
	if (cur->right) traversal(cur->right, false, ans);
}


int sumOfLeftLeaves(TreeNode* root) 
{
	int ans = 0;
	traversal(root, false, ans);
	return ans;
}


int main()
{
	vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
	TreeNode* root = initTree(nums);

	int ans = sumOfLeftLeaves(root);
	cout << ans << endl;

	return 0;
}