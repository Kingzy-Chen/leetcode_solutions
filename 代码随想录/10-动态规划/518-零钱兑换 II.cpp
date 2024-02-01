#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int change(int amount, vector<int>& coins) 
{
	int n = coins.size();
	int bagWeight = amount;

	// dp[j] 表示金额总和为 j 的硬币组合数
	vector<int> dp(amount + 1, 0);

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= amount; j++) {
			if (j >= coins[i]) dp[j] += dp[j - coins[i]];  // 装满背包的方式
			else continue;
		}
	}
	return dp[amount];
}


int main()
{
	int amount1 = 5;
	vector<int> coins1 = {1, 2, 5};
	cout << change(amount1, coins1) << endl;

	int amount2 = 3;
	vector<int> coins2 = {2};
	cout << change(amount2, coins2) << endl;

	int amount3 = 10;
	vector<int> coins3 = {10};
	cout << change(amount3, coins3) << endl;

	return 0;
}