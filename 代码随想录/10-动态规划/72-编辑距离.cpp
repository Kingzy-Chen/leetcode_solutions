#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	字符串编辑距离 (删除/增加/替换)
	word1 = {h o r s e}
	word2 = {r o s}
	ans = 3

	dp[] = 
	    r o s
	  0 1 2 3
	h 1 1 2 3
	o 2 2 1 2
	r 3 2 2 2
	s 4 3 3 2
	e 5 4 4 3
*/

int minDistance(string word1, string word2) 
{
	int n1 = word1.size();
	int n2 = word2.size();

	// dp[i][j] 表示以下标 i - 1 为结尾的 A, 和以下标 j - 1 结尾的 B, 两者的编辑距离
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	// 初始化, 相当于两单词与空字符串的编辑距离
	for (int i = 1; i <= n1; i++) dp[i][0] = i;
	for (int j = 1; j <= n2; j++) dp[0][j] = j;

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			// 遇到相同字符, 等于斜对角元素
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// 否则由左方、上方、斜对角元素递推
			else {
				dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
			}
		}
	}
	return dp[n1][n2];
}


int main()
{
	string word1 = "horse";
	string word2 = "ros";
	cout << minDistance(word1, word2) << endl;

	return 0;
}