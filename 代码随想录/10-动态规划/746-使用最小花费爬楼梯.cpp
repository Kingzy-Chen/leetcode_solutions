#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minCostClimbingStairs(vector<int>& cost) 
{
	int n = cost.size();

	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
	}
	return dp[n];
}


int main()
{
	vector<int> cost1 = {10, 15, 20};
	cout << minCostClimbingStairs(cost1) << endl;

	vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	cout << minCostClimbingStairs(cost2) << endl;

	return 0;
}