#include <iostream>
#include <vector>
#include <stack>
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

// 打印二叉树
void printTree(TreeNode* root)
{
	vector<int> ans;
	postorderTraversal(root, ans);

	for (auto t: ans) cout << t << " ";
	cout << endl;
}


/*递归法*/
void traversal(TreeNode* cur)
{
	if (cur == nullptr) return;
	swap(cur->left, cur->right);
	traversal(cur->left);
	traversal(cur->right);
}

TreeNode* invertTree_v1(TreeNode* root)
{
	if (root == nullptr) return root;
	traversal(root);
	return root;
}


/*迭代法*/
TreeNode* invertTree_v2(TreeNode* root)
{
	if (root == nullptr) return root;

	stack<TreeNode*> stk;
	stk.push(root);

	while (!stk.empty()) {
		TreeNode* cur = stk.top();
		stk.pop();
		swap(cur->left, cur->right);

		if (cur->right != nullptr) stk.push(cur->right);
		if (cur->left != nullptr) stk.push(cur->left);
	}
	return root;
}


int main()
{
	vector<int> nums = {4, 2, 7, 1, 3, 6, 9};
	TreeNode* root1 = initTree(nums);
	TreeNode* root2 = initTree(nums);

	root1 = invertTree_v1(root1);
	printTree(root1);

	root2 = invertTree_v2(root2);
	printTree(root2);

	return 0;
}
