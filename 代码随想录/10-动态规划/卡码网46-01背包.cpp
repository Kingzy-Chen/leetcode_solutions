#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int zeroOneBagProblem(vector<int> weight, vector<int> value, int bagWeight)
{
	// dp[i][j] 表示从下标 0-i 物品中选取放入容量为 j 的背包, 所获得的最大价值
	int n = weight.size();
	vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));

	// 初始化
	for (int j = 0; j <= bagWeight; j++) {
		if (j >= weight[0]) dp[0][j] = value[0];
	}

	// 状态递推
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= bagWeight; j++) {
			if (j >= weight[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n - 1][bagWeight];
}


int main()
{
	vector<int> weight = {1, 3, 4};
	vector<int> value = {15, 20, 30};
	int bagWeight = 4;
	cout << zeroOneBagProblem(weight, value, bagWeight) << endl;

	return 0;
}