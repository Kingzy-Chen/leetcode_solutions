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


void backtracking_v1(int n, int k, int startIdx)
{
	// 符合条件时, 保存当前搜索结果
	if (path.size() == k) {
		result.push_back(path);
		return;
	}

	// 在搜索树的每一层中, 从 [startIdx, n] 的范围中选取一个数字
	for (int i = startIdx; i <= n; i++) {
		path.push_back(i);
		backtracking_v1(n, k, i + 1);  // 选取当前数字 i 后, 下一层搜索从 [i + 1, n] 范围中取值
		path.pop_back();  // 回溯, 撤销节点
	}
}


void backtracking_v2(int n, int k, int startIdx)
{
	if (path.size() == k) {
		result.push_back(path);
		return;
	}

	// 剪枝优化, 假设 n = k = 4, path.size() = 0
	// 则此时要求 i <= 1, 因为从 2 开始取数最终会无法取满 4 个数字, 不过写 i <= n 也没错
	for (int i = startIdx; i <= n - (k - path.size()) + 1; i++) {
		path.push_back(i);
		backtracking_v2(n, k, i + 1);
		path.pop_back();
	}
}


vector<vector<int>> combine(int n, int k)
{
	result.clear();
	path.clear();
	
	// backtracking_v1(n, k, 1);
	backtracking_v2(n, k, 1);
	return result;
}


int main()
{
	int n1 = 4;
	int k1 = 2;
	printResult(combine(n1, k1));

	int n2 = 1;
	int k2 = 1;
	printResult(combine(n2, k2));

	return 0;
}