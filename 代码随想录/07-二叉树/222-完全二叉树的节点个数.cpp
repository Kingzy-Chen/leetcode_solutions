#include <iostream>
#include <vector>
#include <queue>
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


int countNodes(TreeNode* root) 
{
	if (root == nullptr) return 0;
	int cnt = 0;

	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty()) {
		int size = que.size();

		for (int i = 0; i < size; i++) {
			TreeNode* cur = que.front();
			que.pop();
			cnt++;

			if (cur->left) que.push(cur->left);
			if (cur->right) que.push(cur->right);
		}
	}
	return cnt;
}


int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6};
	TreeNode* root = initTree(nums);
	cout << countNodes(root) << endl;
	
	return 0;
}