#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
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
void printResult(vector<string> result)
{
	for (auto s: result) cout << s << endl;
	cout << endl;
}


vector<string> result;
string path;
unordered_map<char, vector<char>> mp;


// 获取数字到字母的映射
unordered_map<char, vector<char>> getMap()
{
	unordered_map<char, vector<char>> mp;
	mp['2'] = vector<char>{'a', 'b', 'c'};
	mp['3'] = vector<char>{'d', 'e', 'f'};
	mp['4'] = vector<char>{'g', 'h', 'i'};
	mp['5'] = vector<char>{'j', 'k', 'l'};
	mp['6'] = vector<char>{'m', 'n', 'o'};
	mp['7'] = vector<char>{'p', 'q', 'r', 's'};
	mp['8'] = vector<char>{'t', 'u', 'v'};
	mp['9'] = vector<char>{'w', 'x', 'y', 'z'};
	return mp;
}


void backtracking(int n, int idx, string digits)
{
	if (path.size() == n) {
		result.push_back(path);
		return;
	}

	// 本题是求多个集合的组合而非同一集合的组合, 所以从 0 开始遍历
	char c = digits[idx];

	for (int i = 0; i < mp[c].size(); i++) {
		path.push_back(mp[c][i]);
		backtracking(n, idx + 1, digits);
		path.pop_back();
	}
}


vector<string> letterCombinations(string digits)
{
	result.clear();
	path.clear();
	int n = digits.size();
	if (n == 0) return result;

	mp = getMap();
	backtracking(n, 0, digits);
	return result;
}


int main()
{
	string digits1 = "23";
	printResult(letterCombinations(digits1));

	string digits2 = "";
	printResult(letterCombinations(digits2));

	string digits3 = "2";
	printResult(letterCombinations(digits3));

	return 0;
}