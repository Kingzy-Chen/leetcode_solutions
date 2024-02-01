#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	背包问题总结:

	1. 背包递推公式:

	问能否装满背包 (或者最多装多少): dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
	问装满背包有几种方法: dp[j] += dp[j - nums[i]]
	问背包装满的最大价值: dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
	问装满背包所有物品的最小个数: dp[j] = min(dp[j], dp[j - coins[i]] + 1)

	2. 遍历顺序:

	01背包: 
	二维数组, 先遍历物品或者先遍历容量都行, 第二层for从小到大遍历
	一维数组, 只能先遍历物品再遍历容量, 第二层for从大到小遍历

	完全背包: 
	一维数组, 先遍历物品再遍历容量, 第二层for从小到大遍历, 求组合数
	一维数组, 先遍历容量再遍历物品, 第二层for从小到大遍历, 求排列数
	组合数不要求顺序, 排列数要求顺序
*/

int completeBagProblem(vector<int> weight, vector<int> value, int bagWeight)
{
	// dp[i][j] 表示从下标 0-i 的物品中选取放入容量为 j 的背包, 所获得的最大价值
	int n = weight.size();
	vector<int> dp(bagWeight + 1, 0);

	// 状态递推
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= bagWeight; j++) {
			if (j >= weight[i]) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			else continue;
		}
	}
	return dp[bagWeight];
}


int main()
{
	vector<int> weight = {1, 3, 4};
	vector<int> value = {15, 20, 30};
	int bagWeight = 4;
	cout << completeBagProblem(weight, value, bagWeight) << endl;

	return 0;
}