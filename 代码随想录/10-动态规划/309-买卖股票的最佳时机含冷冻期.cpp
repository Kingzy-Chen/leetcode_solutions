#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) 
{
	int n = prices.size();

	// dp[i][0] 表示第 i 天不持有股票
	// dp[i][1] 表示第 i 天持有股票
	// dp[i][2] 表示第 i 天处于冷冻期
	vector<vector<int>> dp(n, vector<int>(3, 0));
	dp[0][1] = -prices[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);  // 状态 0 来自状态 0 或 2
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		dp[i][2] = dp[i - 1][1] + prices[i];
	}
	// 最后一天处于冷冻期也是卖出状态, 也要考虑其是否为最大收益
	return max(dp[n - 1][0], dp[n - 1][2]);
}


int main()
{
	vector<int> nums1 = {1, 2, 3, 0, 2};
	cout << maxProfit(nums1) << endl;

	vector<int> nums2 = {1};
	cout << maxProfit(nums2) << endl;

	return 0;
}