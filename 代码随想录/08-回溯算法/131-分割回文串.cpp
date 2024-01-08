#include <iostream>
#include <vector>
#include <cstring>
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
		for (auto s: v) cout << s << " ";
		cout << endl;
	}
	cout << endl;
}


vector<vector<string>> result;
vector<string> path;


// 判断字符串是否为回文串
bool isValid(string s) 
{
	int i = 0;
	int j = s.size() - 1;

	while (i <= j) {
		if (s[i++] != s[j--]) return false;
	}
	return true;
}


void backtracking(string s, int startIdx)
{
	// 规定在字符串的 startIdx 索引位置后进行切割
	if (startIdx >= s.size()) {
		result.push_back(path);
		return;
	}

	// 在循环内部切割子串
	for (int i = startIdx; i < s.size(); i++) {
		string sub_s = s.substr(startIdx, i - startIdx + 1);

		if (isValid(sub_s)) {
			path.push_back(sub_s);
			backtracking(s, i + 1);
			path.pop_back();
		}
		else continue;
	}
}


vector<vector<string>> partition(string s)
{
	result.clear();
	path.clear();
	backtracking(s, 0);
	return result;
}


int main()
{
	string s1 = "aab";
	printResult(partition(s1));

	string s2 = "a";
	printResult(partition(s2));

	return 0;
}