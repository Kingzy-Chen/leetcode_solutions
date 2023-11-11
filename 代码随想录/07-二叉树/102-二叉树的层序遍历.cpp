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


vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> ans;
	if (root == nullptr) return ans;

	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty()) {
		// 记录栈的当前大小, 用来保存每一层的元素, 不能用 que.size(), 因为 que 是会变化的
		int size = que.size();
		// 保存当前层的元素
		vector<int> level;

		for (int i = 0; i < size; i++) {
			TreeNode* cur = que.front();
			que.pop();
			level.push_back(cur->val);

			if (cur->left != nullptr) que.push(cur->left);
			if (cur->right != nullptr) que.push(cur->right);
		}
		ans.push_back(level);
	}
	return ans;
}


int main()
{
	vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
	TreeNode* root = initTree(nums);

	vector<vector<int>> ans = levelOrder(root);
	for (auto level: ans) {
		for (auto t: level) {
			cout << t << " ";
		}
		cout << endl;
	}

	return 0;
}
