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


void backtracking(int targetSum, int startIdx, int sum, vector<int>& candidates)
{
	// 剪枝优化
	if (sum > targetSum) {
		return;
	}

	if (sum == targetSum) {
		result.push_back(path);
		return;
	}

	for (int i = startIdx; i < candidates.size(); i++) {
		sum += candidates[i];
		path.push_back(candidates[i]);
		backtracking(targetSum, i, sum, candidates);  // 由于任一数字可以取无限次, 所以 i 不需要加 1
		path.pop_back();
		sum -= candidates[i];
	}
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	result.clear();
	path.clear();
	backtracking(target, 0, 0, candidates);
	return result;
}


int main()
{
	vector<int> candidates1 = {2, 3, 6, 7};
	int target1 = 7;
	printResult(combinationSum(candidates1, target1));

	vector<int> candidates2 = {2, 3, 5};
	int target2 = 8;
	printResult(combinationSum(candidates2, target2));

	vector<int> candidates3 = {2};
	int target3 = 1;
	printResult(combinationSum(candidates3, target3));

	return 0;
}