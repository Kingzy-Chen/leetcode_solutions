#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	多重背包思路:
	对于最多有 Mi 件数量的物品 i, 将这些 Mi 件物品摊开, 相当于求解 01背包
*/

int multipleBagProblem_v1(vector<int> weight, vector<int> value, vector<int> nums, int bagWeight)
{
	// 在循环外部将物品摊开
	for (int i = 0; i < nums.size(); i++) {
		while (nums[i] > 1) {
			weight.push_back(weight[i]);
			value.push_back(value[i]);
			nums[i] -= 1;
		}
	}

	// 01背包求解
	int n = weight.size();
	vector<int> dp(bagWeight + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = bagWeight; j >= 0; j--) {
			if (j >= weight[i]) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			else continue;
		}
	}
	return dp[bagWeight];
}


int multipleBagProblem_v2(vector<int> weight, vector<int> value, vector<int> nums, int bagWeight)
{
	// 01背包求解
	int n = weight.size();
	vector<int> dp(bagWeight + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = bagWeight; j >= 0; j--) {

			// 在循环内部遍历物品个数
			for (int k = 1; k <= nums[i]; k++) {
				if (j >= k * weight[i]) dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
				else continue;
			}
		}
	}
	return dp[bagWeight];
}


int main()
{
	vector<int> weight = {1, 3, 4};
	vector<int> value = {15, 20, 30};
	vector<int> nums = {2, 3, 2};
	int bagWeight = 10;

	cout << multipleBagProblem_v1(weight, value, nums, bagWeight) << endl;
	cout << multipleBagProblem_v2(weight, value, nums, bagWeight) << endl;

	return 0;
}