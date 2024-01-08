#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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


void traversal(TreeNode* cur, int val) 
{
	if (val > cur->val) {
		// 遍历时遇到空的孩子指针, 添加新节点
		if (cur->right == nullptr) {
			TreeNode* node = new TreeNode(val);
			cur->right = node;
		}
		// 否则继续向下搜索
		else traversal(cur->right, val);
	}

	if (val < cur->val) {
		// 遍历时遇到空的孩子指针, 添加新节点
		if (cur->left == nullptr) {
			TreeNode* node = new TreeNode(val);
			cur->left = node;
		}
		// 否则继续向下搜索
		else traversal(cur->left, val);
	}
}


TreeNode* insertIntoBST(TreeNode* root, int val)
{
	if (root == nullptr) {
		TreeNode* node = new TreeNode(val);
		return node;
	}
	traversal(root, val);
	return root;
}


int main()
{
	vector<int> nums1 = {4, 2, 7, 1, 3};
	TreeNode* root1 = initTree(nums1);

	int val1 = 5;
	printTree(insertIntoBST(root1, val1));

	vector<int> nums2 = {40, 20, 60, 10, 30, 50, 70};
	TreeNode* root2 = initTree(nums2);

	int val2 = 25;
	printTree(insertIntoBST(root2, val2));

	return 0;
}