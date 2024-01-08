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


void backtracking(int startIdx, vector<int>& nums) 
{
	// 由于求的是各个子集, 因此不需要判断条件
	result.push_back(path);

	for (int i = startIdx; i < nums.size(); i++) {
		path.push_back(nums[i]);
		backtracking(i + 1, nums);
		path.pop_back();
	}
}


vector<vector<int>> subsets(vector<int>& nums) 
{
	result.clear();
	path.clear();
	backtracking(0, nums);
	return result;
}


int main()
{
	vector<int> nums1 = {1, 2, 3};
	printResult(subsets(nums1));

	vector<int> nums2 = {0};
	printResult(subsets(nums2));

	return 0;
}