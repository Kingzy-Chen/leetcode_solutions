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
void printResult(vector<vector<char>>& result)
{
	for (auto v: result) {
		for (auto c: v) cout << c;
		cout << endl;
	}
	cout << endl;
}


vector<vector<char>> result;


// 判断数字填写在 (row, col) 位置是否合法
bool isValid(vector<vector<char>>& board, int num, int row, int col)
{
	// 判断相同行是否右重复数字
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == '.') continue;
		if (board[row][i] - '0' == num) return false;
	}

	// 判断相同列是否有重复数字
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == '.') continue;
		if (board[i][col] - '0' == num) return false;
	}

	// 判断 3*3 区域是否有重复数字
	for (int i = (row/3)*3; i < (row/3)*3 + 3; i++) {
		for (int j = (col/3)*3; j < (col/3)*3 + 3; j++) {
			if (board[i][j] == '.') continue;
			if (board[i][j] - '0' == num) return false;
		}
	}
	return true;
}


void backtracking(vector<vector<char>>& board, int row, int col)
{
	// 找到下一个没有数字的位置
	while (row <= 8 && col <= 8 && board[row][col] != '.') {
		if (col == 8) {row += 1; col = 0;}
		else {col += 1;}
	}

	// 当行序号达到 9 时, 终止
	if (row > 8) {
		result = board;
		return;
	}

	// 填入数字 1-9
	for (int i = 1; i <= 9; i++) {
		if (isValid(board, i, row, col) == false) continue;

		board[row][col] = '0' + i;
		backtracking(board, row, col);
		board[row][col] = '.';
	}
}


void solveSudoku(vector<vector<char>>& board) 
{
	backtracking(board, 0, 0);
}


int main()
{
	vector<vector<char>> board = {
		vector<char>{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		vector<char>{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		vector<char>{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		vector<char>{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		vector<char>{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		vector<char>{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		vector<char>{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		vector<char>{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		vector<char>{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	printResult(board);

	solveSudoku(board);
	printResult(result);

	return 0;
}