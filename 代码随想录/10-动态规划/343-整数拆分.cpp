#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int integerBreak(int n) 
{
	vector<int> dp(n + 1, 0);
	dp[2] = 1;

	// dp[i] 表示和为 i 的各数字的最大乘积
	// dp[i] 为两者最大值: j * (i - j) 或 j * dp[i - j]
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i/2; j++) {  // j 遍历至 i/2 即可
			dp[i] = max(dp[i], j * (i - j));
			dp[i] = max(dp[i], j * dp[i - j]);
		}
	}
	return dp[n];
}


int main()
{
	int n1 = 2;
	cout << integerBreak(n1) << endl;

	int n2 = 10;
	cout << integerBreak(n2) << endl;

	return 0;
}