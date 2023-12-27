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


TreeNode* deleteNode(TreeNode* root, int key)
{
	if (root == nullptr) return nullptr;

	// 找到要删除的节点
	if (root->val == key) {

		// 若要删除的节点为叶子节点, 则返回空指针, 相当于让父节点指向空
		if (root->left == nullptr && root->right == nullptr) return nullptr;

		// 若要删除的节点有其中一个子树非空, 则返回它, 相当于让父节点指向这个子树
		else if (root->left != nullptr && root->right == nullptr) return root->left;
		else if (root->left == nullptr && root->right != nullptr) return root->right;

		// 若要删除的节点左右子树都非空
		else {
			// 则将右子树拼接到左子树的右下角, 并将父节点指向左子树
			TreeNode* node = root->left;
			while (node->right != nullptr) node = node->right;

			node->right = root->right;
			return root->left;
		}

	}
	// 递归更新子树
	else {
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}
}


int main()
{
	vector<int> nums = {5, 3, 6, 2, 4, -1, 7};
	TreeNode* root = initTree(nums);

	int key = 3;
	TreeNode* ans = deleteNode(root, key);
	printTree(ans);

	return 0;
}