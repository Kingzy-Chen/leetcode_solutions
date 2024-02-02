#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int climbStairs(int n, int m)
{
	vector<int> steps(m, 0);
	for (int i = 0; i < m; i++) steps[i] = i + 1;

	// dp[j] 表示到达第 j 阶台阶的方法数量
	vector<int> dp(n + 1, 0);

	// 由于是求解排列数, 因此先遍历容量再遍历物品
	dp[0] = 1;
	for (int j = 0; j <= n; j++) {  // 遍历容量
		for (int i = 0; i < m; i++) {  // 遍历物品
			if (j >= steps[i]) dp[j] += dp[j - steps[i]];  // 装满背包的方式
			else continue;
		}
	}
	return dp[n];
}


int main()
{
	int n = 3;
	int m = 2;
	cout << climbStairs(n, m) << endl;

	return 0;
}