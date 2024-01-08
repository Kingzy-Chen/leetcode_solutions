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
	平衡二叉树 AVL:
	二叉树每个节点的左右两个子树的高度差绝对值不超过 1
*/
int getHeight(TreeNode* cur)
{
	if (cur == nullptr) return 0;

	int leftHeight = getHeight(cur->left);
	int rightHeight = getHeight(cur->right);

	// -1 代表左孩子树或右孩子树不平衡, 则当前节点为根的子树也不平衡
	if (leftHeight == -1 || rightHeight == -1) return -1;

	// 若高度差小于等于 1, 则返回当前最大高度
	if (abs(leftHeight - rightHeight) <= 1) {
		return 1 + max(leftHeight, rightHeight);
	}
	// 否则返回不平衡标志 -1
	else {
		return -1;
	}
}


bool isBalanced(TreeNode* root)
{
	if (getHeight(root) == -1) return false;
	else return true;
}


int main()
{
	vector<int> nums1 = {3, 9, 20, -1, -1, 15, 7};
	TreeNode* root1 = initTree(nums1);
	cout << isBalanced(root1) << endl;

	vector<int> nums2 = {1, 2, 2, 3, 3, -1, -1, 4, 4};
	TreeNode* root2 = initTree(nums2);
	cout << isBalanced(root2) << endl;

	return 0;
}