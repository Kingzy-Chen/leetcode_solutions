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


TreeNode* createTree(vector<int>& inorder, vector<int>& postorder) 
{
	// 后序数组最后一位数字是根节点, 确定根节点在中序数组中的位置
	int n = postorder.size();
	int idx = -1;
	for (idx = 0; idx < n; idx++) {
		if (inorder[idx] == postorder[n - 1]) break;
	}

	// 构造根节点
	TreeNode* root = new TreeNode(inorder[idx]);

	if (idx > 0) {
		vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);  // 分割数组, 根节点数字左侧子数组构造左孩子树
		vector<int> left_postorder(postorder.begin(), postorder.begin() + idx);  // 后序数组左子数组索引与中序数组左子数组相同
		root->left = createTree(left_inorder, left_postorder);
	}
	if (idx < n - 1) {
		vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());  // 分割数组, 根节点数字右侧子数组构造右孩子树
		vector<int> right_postorder(postorder.begin() + idx, postorder.end() - 1);  // 移除后序数组最后一位, 截取剩下索引作为后序数组右子数组
		root->right = createTree(right_inorder, right_postorder);
	}
	return root;
}


int main()
{
	vector<int> inorder = {9, 3, 15, 20, 7};
	vector<int> postorder = {9, 15, 7, 20, 3};

	TreeNode* root = createTree(inorder, postorder);
	printTree(root);

	return 0;
}