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


// 层序遍历, 记录每一层第一个节点的值
int findBottomLeftValue(TreeNode* root) 
{
	queue<TreeNode*> que;
	que.push(root);
	int ans = -1;

	while (!que.empty()) {
		int size = que.size();

		for (int i = 0; i < size; i++) {
			TreeNode* t = que.front();
			que.pop();

			if (i == 0) ans = t->val;
			if (t->left != nullptr) que.push(t->left);
			if (t->right != nullptr) que.push(t->right);
		}
	}
	return ans;
}


int main()
{
	vector<int> nums1 = {2, 1, 3};
	TreeNode* root1 = initTree(nums1);
	cout << findBottomLeftValue(root1) << endl;

	vector<int> nums2 = {1, 2, 3, 4, -1, 5, 6, -1, -1, -1, -1, 7};
	TreeNode* root2 = initTree(nums2);
	cout << findBottomLeftValue(root2) << endl;

	return 0;
}