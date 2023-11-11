#include <iostream>
#include <vector>
#include <stack>
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


// 中序遍历 (迭代法)
vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> ans;
	if (root == nullptr) return ans;

	stack<TreeNode*> stk;
	TreeNode* cur = root;  // 使用 cur 指针记录当前节点

	// cur != nullptr 允许进入循环
	while (cur != nullptr || !stk.empty()) {

		// 若当前节点非空, 入栈并将 cur 指向左孩子
		if (cur != nullptr) {
			stk.push(cur);
			cur = cur->left;
		}
		// 若当前节点为空, 则将 cur 指向栈顶元素的右孩子, 并将栈顶元素弹出加入结果集
		else {
			cur = stk.top();
			ans.push_back(cur->val);
			cur = cur->right;
			stk.pop();
		}
	}
	return ans;
}


int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, -1, 7};
	TreeNode* root = initTree(nums);

	vector<int> ans = inorderTraversal(root);
	for (auto t: ans) cout << t << " ";
	cout << endl;

	return 0;
}