#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int numSquares(int n) 
{
	vector<int> nums;
	for (int i = 1; i <= n; i++) {
		if (i * i <= n) nums.push_back(i * i);
	}

	// dp[j] 表示总和为 j 的完全平方数最少数量
	vector<int> dp(n + 1, INT_MAX);

	// 由于是求最小数, 此时有顺序和无顺序没有区别, 先遍历物品或先遍历容量均可
	dp[0] = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j <= n; j++) {
			if (j >= nums[i]) dp[j] = min(dp[j], dp[j - nums[i]] + 1);
			else continue;
		}
	}
	return dp[n];
}


int main()
{
	int n1 = 12;
	cout << numSquares(n1) << endl;

	int n2 = 13;
	cout << numSquares(n2) << endl;

	return 0;
}