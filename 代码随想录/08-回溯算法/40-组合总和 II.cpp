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
void backtracking_v1(int targetSum, int startIdx, int sum, vector<int>& candidates, vector<bool>& used)
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
		// 解集不包括重复组合, 因此需要排序后去重, 剪枝优化
		// used[i - 1] == true, 说明同一树枝 candidates[i - 1] 被使用过
		// used[i - 1] == false, 说明同一树层 candidates[i - 1] 被使用过
		if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

		sum += candidates[i];
		path.push_back(candidates[i]);
		used[i] = true;
		backtracking_v1(targetSum, i + 1, sum, candidates, used);
		used[i] = false;
		path.pop_back();
		sum -= candidates[i];
	}
}


vector<vector<int>> combinationSum2_v1(vector<int>& candidates, int target)
{
	// 对数组排序
	sort(candidates.begin(), candidates.end(), less<int>());
	// 利用 used 数组记录对应位置的数字是否已被使用
	vector<bool> used(candidates.size(), false);

	result.clear();
	path.clear();
	backtracking_v1(target, 0, 0, candidates, used);
	return result;
}


/*解法 2: 排序后利用集合去除同一树层的重复元素*/
void backtracking_v2(int targetSum, int startIdx, int sum, vector<int>& candidates)
{
	// 剪枝优化
	if (sum > targetSum) {
		return;
	}

	if (sum == targetSum) {
		result.push_back(path);
		return;
	}

	// 记录树层内已被使用过的元素
	unordered_set<int> uset;

	for (int i = startIdx; i < candidates.size(); i++) {
		// 剪枝优化, 跳过重复元素
		if (uset.find(candidates[i]) != uset.end()) continue;
		// 加入已使用过的元素
		uset.insert(candidates[i]);

		sum += candidates[i];
		path.push_back(candidates[i]);
		backtracking_v2(targetSum, i + 1, sum, candidates);
		path.pop_back();
		sum -= candidates[i];
	}
}


vector<vector<int>> combinationSum2_v2(vector<int>& candidates, int target)
{
	// 对数组排序
	sort(candidates.begin(), candidates.end(), less<int>());

	result.clear();
	path.clear();
	backtracking_v2(target, 0, 0, candidates);
	return result;
}


int main()
{
	vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
	int target1 = 8;
	printResult(combinationSum2_v1(candidates1, target1));

	vector<int> candidates2 = {2, 5, 2, 1, 2};
	int target2 = 5;
	printResult(combinationSum2_v1(candidates2, target2));

	return 0;
}