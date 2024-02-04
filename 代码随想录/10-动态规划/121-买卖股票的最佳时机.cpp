#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) 
{
	int n = prices.size();

	// dp[i][0] 表示第 i 天不持有股票
	// dp[i][1] 表示第 i 天持有股票
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = -prices[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);  // 注意只有一次交易机会, 所以是 0 - prices[i] 而不是 dp[i - 1][0] - prices[i]
	}
	return dp[n - 1][0];
}


int main()
{
	vector<int> nums1 = {7, 1, 5, 3, 6, 4};
	cout << maxProfit(nums1) << endl;

	vector<int> nums2 = {7, 6, 4, 3, 1};
	cout << maxProfit(nums2) << endl;

	return 0;
}