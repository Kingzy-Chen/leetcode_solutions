#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	字符串最小删除操作数
	word1 = {s e a}
	word2 = {e a t}
	ans = 2

	dp[] = 
	    e a t
	  0 1 2 3
	s 1 2 3 4
	e 2 1 2 3
	a 3 2 1 2
*/

int minDistance(string word1, string word2) 
{
	int n1 = word1.size();
	int n2 = word2.size();

	// dp[i][j] 表示以下标 i - 1 为结尾的 A, 和以下标 j - 1 结尾的 B, 两者删除至相同的最小步数
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	// 初始化, 相当于将两单词分别删除至空字符串的最小步数
	for (int i = 1; i <= n1; i++) dp[i][0] = i;
	for (int j = 1; j <= n2; j++) dp[0][j] = j;

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			// 遇到相同字符, 等于斜对角元素
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// 否则由左方和上方元素递推
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
		}
	}
	return dp[n1][n2];
}


int main()
{
	string word1 = "sea";
	string word2 = "eat";
	cout << minDistance(word1, word2) << endl;

	return 0;
}