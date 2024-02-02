#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int coinChange(vector<int>& coins, int amount) 
{
	int n = coins.size();

	// dp[j] 表示总金额为 j 的最小硬币个数
	vector<unsigned long long> dp(amount + 1, INT_MAX);  // unsigned long long 过样例

	// 由于是求最小数, 此时有顺序和无顺序没有区别, 先遍历物品或先遍历容量均可
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= amount; j++) {
			if (j >= coins[i]) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			else continue;
		}
	}
	// 若数组末尾状态未更新, 则说明无法组合硬币总额为 amount
	if (dp[amount] == INT_MAX) return -1;
	return dp[amount];
}


int main()
{
	vector<int> coins1 = {1, 2, 5};
	int amount1 = 11;
	cout << coinChange(coins1, amount1) << endl;

	vector<int> coins2 = {2};
	int amount2 = 3;
	cout << coinChange(coins2, amount2) << endl;

	vector<int> coins3 = {1};
	int amount3 = 0;
	cout << coinChange(coins3, amount3) << endl;

	return 0;
}