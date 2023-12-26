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


// 中序遍历
void traversal(TreeNode* cur, vector<int>& inorder) 
{
	if (cur == nullptr) return;
	traversal(cur->left, inorder);
	inorder.push_back(cur->val);
	traversal(cur->right, inorder);
}


// 中序遍历二叉搜索树, 得到递增序列, 两两计算元素绝对差
int getMinimumDifference(TreeNode* root) 
{
	vector<int> inorder;
	traversal(root, inorder);

	int minDiff = INT_MAX;
	for (int i = 0; i < inorder.size(); i++) {
		if (i > 0) minDiff = min(minDiff, inorder[i] - inorder[i -1]);
	}
	return minDiff;
}


int main()
{
	vector<int> nums1 = {4, 2, 6, 1, 3};
	TreeNode* root1 = initTree(nums1);
	cout << getMinimumDifference(root1) << endl;

	vector<int> nums2 = {1, 0, 48, -1, -1, 12, 49};
	TreeNode* root2 = initTree(nums2);
	cout << getMinimumDifference(root2) << endl;

	return 0;
}