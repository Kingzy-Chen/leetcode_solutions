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


void backtracking(int targetSum, int k, int startIdx, int sum)
{
	// 剪枝优化
	if (sum > targetSum) {
		return;
	}

	if (path.size() == k) {
		if (sum == targetSum) result.push_back(path);
		return;
	}

	for (int i = startIdx; i <= 9 - (k - path.size()) + 1; i++) {  // 剪枝优化
		sum += i;
		path.push_back(i);
		backtracking(targetSum, k, i + 1, sum);
		path.pop_back();
		sum -= i;
	}
}


vector<vector<int>> combinationSum3(int k, int n)
{
	result.clear();
	path.clear();
	backtracking(n, k, 1, 0);
	return result;
}


int main()
{
	int k1 = 3;
	int n1 = 7;
	printResult(combinationSum3(k1, n1));

	int k2 = 3;
	int n2 = 9;
	printResult(combinationSum3(k2, n2));

	int k3 = 4;
	int n3 = 1;
	printResult(combinationSum3(k3, n3));

	return 0;
}