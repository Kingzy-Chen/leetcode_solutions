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


void backtracking(int startIdx, vector<int>& nums) 
{
	if (path.size() >= 2) {
		result.push_back(path);
	}

	// 由于本题要求递增子序列, 因此不能排序, 只能使用集合进行树层重复元素去除
	unordered_set<int> uset;

	for (int i = startIdx; i < nums.size(); i++) {
		if (path.size() > 0 && path.back() > nums[i]) continue;  // 保持递增
		if (uset.find(nums[i]) != uset.end()) continue;  // 去重
		uset.insert(nums[i]);

		path.push_back(nums[i]);
		backtracking(i + 1, nums);
		path.pop_back();
	}
}


vector<vector<int>> findSubsequences(vector<int>& nums) 
{
	result.clear();
	path.clear();
	backtracking(0, nums);
	return result;
}


int main()
{
	vector<int> nums1 = {4, 6, 7, 7};
	printResult(findSubsequences(nums1));

	vector<int> nums2 = {4, 7, 6, 7};
	printResult(findSubsequences(nums2));

	vector<int> nums3 = {4, 4, 3, 2, 1};
	printResult(findSubsequences(nums3));

	return 0;
}