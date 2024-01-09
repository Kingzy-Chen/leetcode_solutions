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
void printResult(vector<vector<string>> result)
{
	for (auto v: result) {
		for (auto s: v) cout << s << endl;
		cout << endl;
	}
	cout << endl;
}


vector<vector<string>> result;
vector<string> chessboard;


// 判断将皇后放在 (row, col) 位置时是否会产生冲突
bool isValid(int n, int row, int col)
{
	// 排除同列
	for (int i = 0; i < row; i++) {
		if (chessboard[i][col] == 'Q') return false;
	}

	// 排除斜对角
	for (int i = 0; i < row; i++) {
		int c1 = col - (row - i);
		int c2 = col + (row - i);

		if (c1 >= 0 && chessboard[i][c1] == 'Q') return false;
		if (c2 < n && chessboard[i][c2] == 'Q') return false;
	}
	return true;
}


void backtracking(int n, int row)
{
	// 当前行序号达到 n, 终止并保存可行解
	if (row == n) {
		result.push_back(chessboard);
		return;
	}

	// 在第 row 行逐个位置放置皇后
	for (int col = 0; col < n; col++) {
		if (isValid(n, row, col) == false) continue;

		chessboard[row][col] = 'Q';
		backtracking(n, row + 1);
		chessboard[row][col] = '.';
	}
}


vector<vector<string>> solveNQueens(int n)
{
	result.clear();
	chessboard = vector<string>(n, string(n, '.'));
	backtracking(n, 0);
	return result;
}


int main()
{
	int n1 = 4;
	printResult(solveNQueens(n1));

	int n2 = 1;
	printResult(solveNQueens(n2));

	return 0;
}