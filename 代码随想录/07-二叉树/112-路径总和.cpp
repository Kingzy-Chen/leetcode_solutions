#include <iostream>
#include <vector>
#include <queue>
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


bool traversal(TreeNode* cur, int curSum, int targetSum)
{
	curSum = curSum + cur->val;
	if (curSum == targetSum && cur->left == nullptr && cur->right == nullptr) return true;

	bool leftValid = false;
	bool rightValid = false;

	if (cur->left != nullptr) leftValid = traversal(cur->left, curSum, targetSum);
	if (cur->right != nullptr) rightValid = traversal(cur->right, curSum, targetSum);
	return leftValid || rightValid;
}


bool hasPathSum(TreeNode* root, int targetSum)
{
	if (root == nullptr) return false;
	int curSum = 0;
	return traversal(root, curSum, targetSum);
}


int main()
{
	vector<int> nums1 = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1};
	TreeNode* root1 = initTree(nums1);

	int targetSum1 = 22;
	cout << hasPathSum(root1, targetSum1) << endl;

	vector<int> nums2 = {1, 2, 3};
	TreeNode* root2 = initTree(nums2);

	int targetSum2 = 5;
	cout << hasPathSum(root2, targetSum2) << endl;

	return 0;
}