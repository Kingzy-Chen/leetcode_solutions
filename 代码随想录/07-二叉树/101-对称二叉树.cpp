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
bool check(TreeNode* leftTree, TreeNode* rightTree)
{
	// 比较左右子树根节点是否同时为空
	if (leftTree == nullptr && rightTree != nullptr) return false;
	else if (leftTree != nullptr && rightTree == nullptr) return false;
	else if (leftTree == nullptr && rightTree == nullptr) return true;
	// 比较根节点的数值是否相等
	else if (leftTree->val != rightTree->val) return false;

	// 比较内侧子树和外侧子树
	bool inside = check(leftTree->right, rightTree->left);
	bool outside = check(leftTree->left, rightTree->right);
	return inside && outside;
}

bool isSymmetric_v1(TreeNode* root)
{
	// 递归比较左子树和右子树是否对称
	if (root == nullptr) return true;
	return check(root->left, root->right);
}


/*迭代法*/
bool isSymmetric_v2(TreeNode* root)
{
	if (root == nullptr) return true;

	stack<TreeNode*> stk;
	stk.push(root->left);
	stk.push(root->right);

	while (!stk.empty()) {
		// 两两节点出栈
		TreeNode* rightTree = stk.top();  stk.pop();
		TreeNode* leftTree = stk.top();  stk.pop();

		// 同时为空
		if (leftTree == nullptr && rightTree == nullptr) {
			continue;
		}
		// 不同时为空
		if (leftTree == nullptr || rightTree == nullptr || leftTree->val != rightTree->val) {
			return false;
		}

		// 内测子树
		stk.push(leftTree->right);
		stk.push(rightTree->left);
		// 外侧子树
		stk.push(leftTree->left);
		stk.push(rightTree->right);
	}
	return true;
}


int main()
{
	vector<int> nums1 = {1, 2, 2, 3, 4, 4, 3};
	TreeNode* root1 = initTree(nums1);
	cout << isSymmetric_v1(root1) << endl;

	vector<int> nums2 = {1, 2, 2, -1, 3, -1, 3};
	TreeNode* root2 = initTree(nums2);
	cout << isSymmetric_v2(root2) << endl;

	return 0;
}