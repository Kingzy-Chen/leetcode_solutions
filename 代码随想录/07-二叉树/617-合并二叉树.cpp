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

// 前序遍历输出二叉树
void postorderTraversal(TreeNode* root, vector<int>& ans)
{
	if (root == nullptr) return;
	ans.push_back(root->val);      // 中
	postorderTraversal(root->left, ans);    // 左
	postorderTraversal(root->right, ans);   // 右
}

void printTree(TreeNode* root)
{
	vector<int> ans;
	postorderTraversal(root, ans);

	for (auto t: ans) cout << t << " ";
	cout << endl;
}


TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
{
	if (root1 == nullptr) return root2;
	if (root2 == nullptr) return root1;

	TreeNode* root = new TreeNode(root1->val + root2->val);
	root->left = mergeTrees(root1->left, root2->left);
	root->right = mergeTrees(root1->right, root2->right);
	return root;
}


int main()
{
	vector<int> nums1 = {1, 3, 2, 5};
	vector<int> nums2 = {2, 1, 3, -1, 4, -1, 7};

	TreeNode* root1 = initTree(nums1);
	TreeNode* root2 = initTree(nums2);
	TreeNode* root = mergeTrees(root1, root2);

	printTree(root);
	return 0;
}