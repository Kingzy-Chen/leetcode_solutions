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
void printResult(vector<string> result)
{
	for (auto s: result) cout << s << endl;
	cout << endl;
}


vector<string> result;
string path;


// 判断子串是否为合法的 IP 数字
bool isValid(string s)
{
	// 不包含前导零
	if (s.size() > 1 && s[0] == '0') return false;
	// 范围在 0-255 内
	if (s.size() > 0 && s.size() < 4 && stoi(s) >= 0 && stoi(s) <= 255) return true;
	// 其他不合法情况
	return false;
}


// splitNum 记录切割的次数
void backtracking(string s, int splitNum, int startIdx)
{
	// 剪枝优化
	if (startIdx > s.size() || splitNum > 4) {
		return;
	}

	// 当切割次数等于 4 时, 达到终止条件
	if (splitNum == 4) {
		if (startIdx == s.size()) {
			// 去除 path 最后一个小数点
			result.push_back(path.substr(0, path.size() - 1));
			return;
		}
	}
	
	for (int i = startIdx; i < s.size(); i++) {
		string sub_s = s.substr(startIdx, i - startIdx + 1);

		if (isValid(sub_s)) {
			path += sub_s;  // 加入数字段
			path += ".";  // 加入小数点
			backtracking(s, splitNum + 1, i + 1);
			path.pop_back();  // 删除小数点
			path = path.substr(0, path.size() - (i - startIdx + 1));  // 删除数字段
		}
		else continue;
	}
}


vector<string> restoreIpAddresses(string s) 
{
	result.clear();
	path.clear();
	backtracking(s, 0, 0);
	return result;
}


int main()
{
	string s1 = "25525511135";
	printResult(restoreIpAddresses(s1));

	string s2 = "0000";
	printResult(restoreIpAddresses(s2));

	string s3 = "101023";
	printResult(restoreIpAddresses(s3));

	return 0;
}