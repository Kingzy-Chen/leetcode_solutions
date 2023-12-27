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

// 获取等于特定值的树节点
TreeNode* getNode(TreeNode* root, int val)
{
	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty()) {
		int size = que.size();

		for (int i = 0; i < size; i++) {
			TreeNode* cur = que.front();
			que.pop();
			if (cur->val == val) return cur;

			if (cur->left != nullptr) que.push(cur->left);
			if (cur->right != nullptr) que.push(cur->right);
		}
	}
	return nullptr;
}


/*自顶向下遍历*/
void traversal(TreeNode* cur, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mp)
{
	// 利用 map 记录节点的父节点
	if (cur == nullptr) return;
	mp[cur] = parent;
	traversal(cur->left, cur, mp);
	traversal(cur->right, cur, mp);
}


vector<TreeNode*> getPath(TreeNode* cur, TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp)
{
	// 获取 cur 到达根节点的路径
	vector<TreeNode*> path;
	while (cur != nullptr) {
		path.push_back(cur);
		cur = mp[cur];
	}
	return path;
}


TreeNode* lowestCommonAncestor_v1(TreeNode* root, TreeNode* p, TreeNode* q)
{
	unordered_map<TreeNode*, TreeNode*> mp;
	traversal(root, nullptr, mp);

	vector<TreeNode*> path1 = getPath(p, root, mp);
	vector<TreeNode*> path2 = getPath(q, root, mp);

	// 对比 p 和 q 到达根节点的路径来判断公共祖先
	for (auto i: path1) {
		for (auto j: path2) {
			if (i == j) return i;
		}
	}
	return nullptr;
}


/*自底向上遍历*/
TreeNode* lowestCommonAncestor_v2(TreeNode* root, TreeNode* p, TreeNode* q)
{
	// 除非是 p 或 q, 否则叶子节点都向上返回空指针
	if (root == nullptr) return nullptr;
	if (root == p || root == q) return root;

	TreeNode* left = lowestCommonAncestor_v2(root->left, p, q);
	TreeNode* right = lowestCommonAncestor_v2(root->right, p, q);

	// 若 left 或 right 有其一为空, 则向上返回非空的指针
	if (left != nullptr && right == nullptr) return left;
	else if (left == nullptr && right != nullptr) return right;
	else if (left == nullptr && right == nullptr) return nullptr;
	// 若 left 和 right 都不为空, 则说明当前节点是公共祖先, 向上返回当前节点的指针
	else return root;
}


int main()
{
	vector<int> nums = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
	TreeNode* root = initTree(nums);

	TreeNode* p1 = getNode(root, 5);
	TreeNode* q1 = getNode(root, 1);
	TreeNode* ans1 = lowestCommonAncestor_v1(root, p1, q1);
	cout << ans1->val << endl;

	TreeNode* p2 = getNode(root, 5);
	TreeNode* q2 = getNode(root, 4);
	TreeNode* ans2 = lowestCommonAncestor_v2(root, p2, q2);
	cout << ans2->val << endl;

	return 0;
}