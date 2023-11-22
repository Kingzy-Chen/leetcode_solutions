#include <iostream>
#include <vector>
#include <cstring>
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


/*回溯法*/
void traversal(TreeNode* cur, string path, vector<string>& ans)
{
	string val = to_string(cur->val);
	path += val;

	// 回溯终止条件
	if (cur->left == nullptr && cur->right == nullptr) {
		ans.push_back(path);
	}

	// 递归, 注意 path 是值传递, ans 是引用传递
	if (cur->left) traversal(cur->left, path + "->", ans);
	if (cur->right) traversal(cur->right, path + "->", ans);
}

vector<string> binaryTreePaths(TreeNode* root) 
{
	vector<string> ans;
	string path = "";
	if (root == nullptr) return ans;

	traversal(root, path, ans);
	return ans;
}


int main()
{
	vector<int> nums = {1, 2, 3, -1, 5};
	TreeNode* root = initTree(nums);

	vector<string> ans = binaryTreePaths(root);
	for (auto s: ans) {
		cout << s << endl;
	}

	return 0;
}