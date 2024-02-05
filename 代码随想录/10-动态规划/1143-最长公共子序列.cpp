#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	最长公共子序列 (不要求连续)
	text1 = {a b c d e}
	text2 = {a c e}
	ans = {a c e}

	dp[] = 
	    a c e
	  0 0 0 0
	a 0 1 1 1
	b 0 1 1 1
	c 0 1 2 2
	d 0 1 2 2
	e 0 1 2 3
*/

int longestCommonSubsequence(string text1, string text2) 
{
	int n1 = text1.size();
	int n2 = text2.size();
	int maxLength = 0;

	// dp[i][j] 表示以下标 i - 1 为结尾的 A, 和以下标 j - 1 结尾的 B, 最长公共子序列的长度
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			// 遇到相同字符, 斜对角 + 1
			if (text1[i - 1] == text2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			// 否则用左方和上方元素递推
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			maxLength = max(maxLength, dp[i][j]);
		}
	}
	return maxLength;
}


int main()
{
	string text1 = "abcde";
	string text2 = "ace";
	cout << longestCommonSubsequence(text1, text2) << endl;

	return 0;
}