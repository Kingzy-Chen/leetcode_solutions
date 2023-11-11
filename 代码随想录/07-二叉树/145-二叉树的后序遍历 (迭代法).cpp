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


// 后序遍历 (迭代法)
vector<int> postorderTraversal(TreeNode* root) 
{
	vector<int> ans;
	if (root == nullptr) return ans;

	stack<TreeNode*> stk;
	stk.push(root);

	while (!stk.empty()) {
		TreeNode* p = stk.top();
		ans.push_back(p->val);  // 中
		stk.pop();

		// 首先, 按照 中右左 输出
		if (p->left != nullptr) stk.push(p->left);  // 左
		if (p->right != nullptr) stk.push(p->right);  // 右
	}
	// 其次, 反转结果数组, 中右左 -> 左右中
	reverse(ans.begin(), ans.end());
	return ans;
}


int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, -1, 7};
	TreeNode* root = initTree(nums);

	vector<int> ans = postorderTraversal(root);
	for (auto t: ans) cout << t << " ";
	cout << endl;

	return 0;
}