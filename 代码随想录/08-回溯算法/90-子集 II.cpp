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
void backtracking_v1(int startIdx, vector<int>& nums, vector<bool>& used)
{
	// 由于求的是各个子集, 因此不需要判断条件
	result.push_back(path);

	for (int i = startIdx; i < nums.size(); i++) {
		// 解集不包括重复组合, 因此需要排序后去重, 剪枝优化
		// used[i - 1] == true, 说明同一树枝 nums[i - 1] 被使用过
		// used[i - 1] == false, 说明同一树层 nums[i - 1] 被使用过
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

		path.push_back(nums[i]);
		used[i] = true;
		backtracking_v1(i + 1, nums, used);
		used[i] = false;
		path.pop_back();
	}
}


vector<vector<int>> subsetsWithDup_v1(vector<int>& nums) 
{
	// 对数组排序
	sort(nums.begin(), nums.end(), less<int>());
	// 利用 used 数组记录对应位置的数字是否已被使用
	vector<bool> used(nums.size(), false);

	result.clear();
	path.clear();
	backtracking_v1(0, nums, used);
	return result;
}


/*解法 2: 排序后利用集合去除同一树层的重复元素*/
void backtracking_v2(int startIdx, vector<int>& nums)
{
	// 由于求的是各个子集, 因此不需要判断条件
	result.push_back(path);

	// 记录树层内已被使用过的元素
	unordered_set<int> uset;

	for (int i = startIdx; i < nums.size(); i++) {
		// 剪枝优化, 跳过重复元素
		if (uset.find(nums[i]) != uset.end()) continue;
		// 加入已使用过的元素
		uset.insert(nums[i]);

		path.push_back(nums[i]);
		backtracking_v2(i + 1, nums);
		path.pop_back();
	}
}


vector<vector<int>> subsetsWithDup_v2(vector<int>& nums) 
{
	// 对数组排序
	sort(nums.begin(), nums.end(), less<int>());

	result.clear();
	path.clear();
	backtracking_v2(0, nums);
	return result;
}


int main()
{
	vector<int> nums1 = {1, 2, 2};
	printResult(subsetsWithDup_v1(nums1));

	vector<int> nums2 = {0};
	printResult(subsetsWithDup_v1(nums2));

	return 0;
}