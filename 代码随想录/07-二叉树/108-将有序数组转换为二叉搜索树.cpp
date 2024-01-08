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


TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	int n = nums.size();
	int mid = n / 2;  // 找到有序数组最中间的元素

	TreeNode* root = new TreeNode(nums[mid]);
	if (0 < mid) {
		vector<int> leftnums = vector<int>(nums.begin(), nums.begin() + mid);  // 分割数组, 中间元素左侧子数组构造左孩子树
		root->left = sortedArrayToBST(leftnums);
	}
	if (mid < n - 1) {
		vector<int> rightnums = vector<int>(nums.begin() + mid + 1, nums.end());  // 分割数组, 中间元素右侧子数组构造右孩子树
		root->right = sortedArrayToBST(rightnums);
	}
	return root;
}


int main()
{
	vector<int> nums = {-10, -3, 0, 5, 9};
	TreeNode* root = sortedArrayToBST(nums);
	printTree(root);

	return 0;
}