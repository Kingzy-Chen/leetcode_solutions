#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(int k, vector<int>& prices) 
{
	int n = prices.size();

	// dp[i][0] 表示第 i 天不持有股票, 且从未买卖股票
	// dp[i][j] 表示第 i 天持有股票, 第 j 次买入
	// dp[i][j + 1] 表示第 i 天不持有股票, 第 j 次卖出
	vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));

	for (int j = 1; j < 2 * k; j+= 2) {
		dp[0][j] = -prices[0];
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0];

		for (int j = 1; j <= 2 * k; j += 2) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
			dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
		}
	}
	return dp[n - 1][2 * k];
}


int main()
{
	vector<int> nums1 = {2, 4, 1};
	int k1 = 2;
	cout << maxProfit(k1, nums1) << endl;

	vector<int> nums2 = {3, 2, 6, 5, 0, 3};
	int k2 = 2;
	cout << maxProfit(k2, nums2) << endl;

	return 0;
}