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


// 中序遍历
void traversal(TreeNode* cur, unordered_map<int, int>& mp) 
{
	if (cur == nullptr) return;
	traversal(cur->left, mp);
	mp[cur->val] += 1;
	traversal(cur->right, mp);
}


// 自定义排序
bool static cmp(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.second > p2.second;
}


// 中序遍历二叉搜索树, 利用 map 记录数字出现次数
vector<int> findMode(TreeNode* root) 
{
	unordered_map<int, int> mp;  // num -> cnt
	traversal(root, mp);

	vector<pair<int, int>> v(mp.begin(), mp.end());  // 将 map 存储为数组
	sort(v.begin(), v.end(), cmp);  // 按照数字出现次数降序排序

	vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == v[0].second) ans.push_back(v[i].first);
	}
	return ans;
}


int main()
{
	vector<int> nums1 = {1, -1, 2, -1, -1, 2};
	TreeNode* root1 = initTree(nums1);

	vector<int> ans1 = findMode(root1);
	for (auto t: ans1) cout << t << " ";
	cout << endl;

	vector<int> nums2 = {1, 1, 1, 2, 2, 2, 3};
	TreeNode* root2 = initTree(nums2);

	vector<int> ans2 = findMode(root2);
	for (auto t : ans2) cout << t << " ";
	cout << endl;

	return 0;
}