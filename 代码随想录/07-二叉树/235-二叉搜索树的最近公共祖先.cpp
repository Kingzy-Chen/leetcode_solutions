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
TreeNode* traversal(TreeNode* cur, int pVal, int qVal)
{
	// 自顶向下遍历的第一个值位于 [pVal, qVal] 区间内的节点就是最近公共祖先
	if (cur == nullptr) return nullptr;
	if (pVal <= cur->val && cur->val <= qVal) return cur;

	TreeNode* left = traversal(cur->left, pVal, qVal);
	TreeNode* right = traversal(cur->right, pVal, qVal);

	// 若 left 或 right 有其一为空, 则向上返回非空的指针
	if (left != nullptr && right == nullptr) return left;
	else if (left == nullptr && right != nullptr) return right;
	else return nullptr;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	int pVal = p->val;
	int qVal = q->val;
	if (pVal > qVal) swap(pVal, qVal);  // 保证 pVal <= qVal

	TreeNode* ans = traversal(root, pVal, qVal);
	return ans;
}


int main()
{
	vector<int> nums = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
	TreeNode* root = initTree(nums);

	TreeNode* p1 = getNode(root, 2);
	TreeNode* q1 = getNode(root, 8);
	TreeNode* ans1 = lowestCommonAncestor(root, p1, q1);
	cout << ans1->val << endl;

	TreeNode* p2 = getNode(root, 2);
	TreeNode* q2 = getNode(root, 4);
	TreeNode* ans2 = lowestCommonAncestor(root, p2, q2);
	cout << ans2->val << endl;

	return 0;
}