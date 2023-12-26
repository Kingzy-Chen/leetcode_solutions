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


// 中序遍历二叉搜索树, 序列应保持严格递增
bool isValidBST(TreeNode* root) 
{
	vector<int> inorder;
	traversal(root, inorder);

	for (int i = 0; i < inorder.size(); i++) {
		if (i > 0 && inorder[i - 1] >= inorder[i]) return false;
	}
	return true;
}


int main()
{
	vector<int> nums1 = {2, 1, 3};
	TreeNode* root1 = initTree(nums1);
	cout << isValidBST(root1) << endl;

	vector<int> nums2 = {5, 1, 4, -1, -1, 3, 6};
	TreeNode* root2 = initTree(nums2);
	cout << isValidBST(root2) << endl;

	return 0;
}