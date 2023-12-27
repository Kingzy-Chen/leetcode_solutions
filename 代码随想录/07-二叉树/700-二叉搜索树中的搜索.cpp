#include <iostream>
#include <vector>
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

// 前序遍历输出二叉树
void postorderTraversal(TreeNode* root, vector<int>& ans)
{
	if (root == nullptr) return;
	ans.push_back(root->val);               // 中
	postorderTraversal(root->left, ans);    // 左
	postorderTraversal(root->right, ans);   // 右
}

// 打印二叉树
void printTree(TreeNode* root)
{
	vector<int> ans;
	postorderTraversal(root, ans);

	for (auto t: ans) cout << t << " ";
	cout << endl;
}


/*
	二叉搜索树 BST:
	节点左子树只包含小于当前节点的数;
	节点右子树只包含大于当前节点的数;
	所有左子树和右子树本身必须也是二叉搜索树
*/
TreeNode* searchBST(TreeNode* root, int val)
{
	if (root == nullptr) return nullptr;
	if (root->val == val) return root;

	if (root->val > val) return searchBST(root->left, val);
	if (root->val < val) return searchBST(root->right, val);
	return nullptr;
}


int main()
{
	vector<int> nums = {4, 2, 7, 1, 3};
	TreeNode* root = initTree(nums);
	int val1 = 2;
	int val2 = 5;

	printTree(searchBST(root, val1));
	cout << endl;
	printTree(searchBST(root, val2));
	cout << endl;

	return 0;
}