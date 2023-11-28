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


TreeNode* createTree(vector<int>& nums) 
{
	// 找到最大值在数组中的位置
	int maxIdx = -1;
	int maxVal = -1;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > maxVal) {
			maxVal = nums[i];
			maxIdx = i;
		}
	}

	// 构造根节点
	TreeNode* root = new TreeNode(maxVal);

	if (maxIdx > 0) {
		vector<int> leftnums(nums.begin(), nums.begin() + maxIdx);  // 切割数组, 最大值左侧子数组构造左孩子树
		root->left = createTree(leftnums);
	}
	if (maxIdx < nums.size() - 1) {
		vector<int> rightnums(nums.begin() + maxIdx + 1, nums.end());  // 切割数组, 最大值右侧子数组构造右孩子树
		root->right = createTree(rightnums);
	}
	return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
	TreeNode* root = createTree(nums);
	return root;
}


int main()
{
	vector<int> nums = {3, 2, 1, 6, 0, 5};
	TreeNode* root = constructMaximumBinaryTree(nums);

	printTree(root);
	return 0;
}