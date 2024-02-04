#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices, int fee) 
{
	int n = prices.size();

	// dp[i][0] 表示第 i 天不持有股票
	// dp[i][1] 表示第 i 天持有股票
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = -prices[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	return dp[n - 1][0];
}


int main()
{
	vector<int> nums1 = {1, 3, 2, 8, 4, 9};
	int fee1 = 2;
	cout << maxProfit(nums1, fee1) << endl;

	vector<int> nums2 = {1, 3, 7, 5, 10, 3};
	int fee2 = 3;
	cout << maxProfit(nums2, fee2) << endl;

	return 0;
}