#include <iostream>
#include <vector>
#include <unordered_map>
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


/*树形 DP*/
vector<int> traversal_v1(TreeNode* cur)
{
	// 规定长度为 2 的数组来表示树节点状态: dp[0] 不偷窃当前节点, dp[1] 偷窃当前节点
	if (cur == nullptr) return {0, 0};

	// 自底向上偷窃, 采用后序遍历
	vector<int> dp_left = traversal_v1(cur->left);
	vector<int> dp_right = traversal_v1(cur->right);

	// 不偷窃当前节点 cur, 则可以选择偷或不偷左右孩子节点
	int val1 = max(dp_left[0], dp_left[1]) + max(dp_right[0], dp_right[1]);

	// 偷窃当前节点 cur, 则不可能偷窃左右孩子节点
	int val2 = cur->val + dp_left[0] + dp_right[0];

	return {val1, val2};
}


int rob_v1(TreeNode* root)
{
	vector<int> ans = traversal_v1(root);
	return max(ans[0], ans[1]);
}


/*记忆化递归*/
unordered_map<TreeNode*, int> mp;  // 利用哈希表进行记忆化查询

int traversal_v2(TreeNode* cur)
{
	if (cur == nullptr) return 0;
	if (cur->left == nullptr && cur->right == nullptr) return cur->val;
	if (mp[cur]) return mp[cur];

	// 不偷窃当前节点 cur, 则可以选择偷或不偷左右孩子节点
	int val1 = traversal_v2(cur->left) + traversal_v2(cur->right);

	// 偷窃当前节点 cur, 则不可能偷窃左右孩子节点, 考虑孙子节点
	int val2 = cur->val;
	if (cur->left) val2 += traversal_v2(cur->left->left) + traversal_v2(cur->left->right);
	if (cur->right) val2 += traversal_v2(cur->right->left) + traversal_v2(cur->right->right);

	// 存储结果
	mp[cur] = max(val1, val2);
	return max(val1, val2);
}


int rob_v2(TreeNode* root)
{
	mp.clear();
	return traversal_v2(root);
}



int main()
{
	vector<int> nums1 = {3, 2, 3, -1, 3, -1, 1};
	TreeNode* root1 = initTree(nums1);
	cout << rob_v1(root1) << endl;

	vector<int> nums2 = {3, 4, 5, 1, 3, -1, 1};
	TreeNode* root2 = initTree(nums2);
	cout << rob_v2(root2) << endl;

	return 0;
}