#include <iostream>
#include <vector>
#include <algorithm>
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


void backtracking(vector<int>& nums, vector<bool>& used)
{
	if (path.size() == nums.size()) {
		result.push_back(path);
		return;
	}

	// 由于是求排列, 因此从 0 开始遍历而非 startIdx
	for (int i = 0; i < nums.size(); i++) {
		// 若某位置的数字已被使用, 则跳过
		if (used[i] == true) continue;  

		path.push_back(nums[i]);
		used[i] = true;
		backtracking(nums, used);
		used[i] = false;
		path.pop_back();
	}
}


vector<vector<int>> permute(vector<int>& nums) 
{
	vector<bool> used(nums.size(), false);

	result.clear();
	path.clear();
	backtracking(nums, used);
	return result;
}


int main()
{
	vector<int> nums1 = {1, 2, 3};
	printResult(permute(nums1));

	vector<int> nums2 = {0, 1};
	printResult(permute(nums2));

	vector<int> nums3 = {1};
	printResult(permute(nums3));

	return 0;
}