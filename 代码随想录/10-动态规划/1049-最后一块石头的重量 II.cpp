#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int lastStoneWeightII(vector<int>& stones)
{
	// 计算重量总和
	int sum = 0;
	for (auto i: stones) sum += i;

	// 尽量将石头凑到重量总和的一半, dp[j] 表示选取石头放入容量为 j 的背包所获得的最大重量和
	int bagWeight = sum / 2;
	int n = stones.size();
	vector<int> dp(bagWeight + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = bagWeight; j >= 0; j--) {
			if (j >= stones[i]) dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			else continue;
		}
	}
	// 减去粉碎掉的重量
	return sum - 2 * dp[bagWeight];
}


int main()
{
	vector<int> stones1 = {2, 7, 4, 1, 8, 1};
	cout << lastStoneWeightII(stones1) << endl;

	vector<int> stones2 = {31, 26, 33, 21, 40};
	cout << lastStoneWeightII(stones2) << endl;

	return 0;
}