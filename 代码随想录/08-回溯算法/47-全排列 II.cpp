#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
	回溯算法模板:
	void backtracking(参数) {
		if (终止条件) {
			... ... // 存放结果
			return;
		}

		for (选择: 本层集合中元素 (树中节点孩子的数量就是集合的大小)) {
			... ... // 处理节点
			backtracking(路径, 选择列表); // 递归
			... ... // 回溯, 撤销处理结果
		}
	}
*/

// 打印结果
void printResult(vector<vector<int>> result)
{
	for (auto v: result) {
		for (auto i: v) cout << i << " ";
		cout << endl;
	}
	cout << endl;
}


vector<vector<int>> result;
vector<int> path;


/*解法 1: 排序后利用 used 数组去除同一树层内的重复元素*/
void backtracking_v1(vector<int>& nums, vector<bool>& used)
{
	if (path.size() == nums.size()) {
		result.push_back(path);
		return;
	}

	// 由于是求排列, 因此从 0 开始遍历而非 startIdx
	for (int i = 0; i < nums.size(); i++) {

		// 解集不包括重复组合, 因此需要排序后去重, 剪枝优化
		// used[i - 1] == true, 说明同一树枝 nums[i - 1] 被使用过
		// used[i - 1] == false, 说明同一树层 nums[i - 1] 被使用过
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

		// 若某位置的数字已被使用, 则跳过
		if (used[i] == true) continue;

		path.push_back(nums[i]);
		used[i] = true;
		backtracking_v1(nums, used);
		used[i] = false;
		path.pop_back();
	}
}


vector<vector<int>> permuteUnique_v1(vector<int>& nums) 
{
	sort(nums.begin(), nums.end(), less<int>());
	vector<bool> used(nums.size(), false);

	result.clear();
	path.clear();
	backtracking_v1(nums, used);
	return result;
}


/*解法 2: 排序后利用集合去除同一树层的重复元素*/
void backtracking_v2(vector<int>& nums, vector<bool>& used)
{
	if (path.size() == nums.size()) {
		result.push_back(path);
		return;
	}

	// 记录树层内已被使用过的元素
	unordered_set<int> uset;

	// 由于是求排列, 因此从 0 开始遍历而非 startIdx
	for (int i = 0; i < nums.size(); i++) {
		
		// 剪枝优化, 跳过重复元素
		if (uset.find(nums[i]) != uset.end()) continue;
		// 若某位置的数字已被使用, 则跳过
		if (used[i] == true) continue;

		// 加入已使用过的元素
		uset.insert(nums[i]);

		path.push_back(nums[i]);
		used[i] = true;
		backtracking_v2(nums, used);
		used[i] = false;
		path.pop_back();
	}
}


vector<vector<int>> permuteUnique_v2(vector<int>& nums) 
{
	sort(nums.begin(), nums.end(), less<int>());
	vector<bool> used(nums.size(), false);

	result.clear();
	path.clear();
	backtracking_v2(nums, used);
	return result;
}


int main()
{
	vector<int> nums1 = {1, 1, 2};
	printResult(permuteUnique_v1(nums1));

	vector<int> nums2 = {1, 2, 3};
	printResult(permuteUnique_v1(nums2));

	return 0;
}