#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int findMaxForm(vector<string>& strs, int m, int n)
{
	// 统计每个字符串的 0 和 1 数量
	vector<int> zeroNum(strs.size(), 0);
	vector<int> oneNum(strs.size(), 0);

	for (int i = 0; i < strs.size(); i++) {
		for (char c: strs[i]) {
			if (c == '0') zeroNum[i] += 1;
			if (c == '1') oneNum[i] += 1;
		}
	}

	// 三维数组
	// dp[k][i][j] 表示从下标 0-k 的字符串中选取放入 '0' 容量为 i 且 '1' 容量为 j 的背包所获得的最大子集大小
	vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

	// 初始化
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i >= zeroNum[0] && j >= oneNum[0]) dp[0][i][j] = 1;
		}
	}
	// 状态递推
	for (int k = 1; k < strs.size(); k++) {
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {

				if (i >= zeroNum[k] && j >= oneNum[k]) {
					dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - zeroNum[k]][j - oneNum[k]] + 1);
				}
				else dp[k][i][j] = dp[k - 1][i][j];
			}
		}
	}
	return dp[strs.size() - 1][m][n];
}


int main()
{
	vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
	int m1 = 5;
	int n1 = 3;
	cout << findMaxForm(strs1, m1, n1) << endl;

	vector<string> strs2 = {"10", "0", "1"};
	int m2 = 1;
	int n2 = 1;
	cout << findMaxForm(strs2, m2, n2) << endl;

	return 0;
}