#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) 
{
	int n = prices.size();

	// dp[i][0] 表示第 i 天不持有股票, 且从未买卖股票
	// dp[i][1] 表示第 i 天持有股票, 第一次买入
	// dp[i][2] 表示第 i 天不持有股票, 第一次卖出
	// dp[i][3] 表示第 i 天持有股票, 第二次买入
	// dp[i][4] 表示第 i 天不持有股票, 第二次卖出
	vector<vector<int>> dp(n, vector<int>(5, 0));
	dp[0][1] = -prices[0];
	dp[0][3] = -prices[0];  // 注意第二次买入的初始值要设成 -prices[0]

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
		dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
		dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
	}
	return dp[n - 1][4];
}


int main()
{
	vector<int> nums1 = {3, 3, 5, 0, 0, 3, 1, 4};
	cout << maxProfit(nums1) << endl;

	vector<int> nums2 = {1, 2, 3, 4, 5};
	cout << maxProfit(nums2) << endl;

	vector<int> nums3 = {7, 6, 4, 3, 1};
	cout << maxProfit(nums3) << endl;

	vector<int> nums4 = {1};
	cout << maxProfit(nums4) << endl;

	return 0;
}