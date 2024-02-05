#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


// 原理与 1143-最长公共子序列 相同
bool isSubsequence(string s, string t) 
{
	int n1 = s.size();
	int n2 = t.size();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// 判断最长公共子序列长度是否与 s 的长度相同
	return dp[n1][n2] == n1;
}


int main()
{
	string s1 = "abc";
	string t1 = "ahbgdc";
	cout << isSubsequence(s1, t1) << endl;

	string s2 = "axc";
	string t2 = "ahbgdc";
	cout << isSubsequence(s2, t2) << endl;

	return 0;
}
