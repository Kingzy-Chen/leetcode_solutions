#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int findTargetSumWays(vector<int>& nums, int target)
{
	// 正号数字 + 负号数字 = target
	// 正号数字 - 负号数字 = sum
	// 正号数字 = (target + sum) / 2
	int sum = 0;
	for (auto i: nums) sum += i;

	// 无法组成表达式的情况
	if (abs(target) > sum) return 0;
	if ((target + sum) % 2 == 1) return 0;

	// dp[j] 表示正数数字总和为 j 的数字搭配有 dp[j] 种
	int bagWeight = (sum + target) / 2;
	int n = nums.size();
	vector<int> dp(bagWeight + 1, 0);

	// dp[0] 必须初始化为 1 才能递推出后续状态
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = bagWeight; j >= 0; j--) {
			if (j >= nums[i]) dp[j] += dp[j - nums[i]];  // 装满背包的方式
			else continue;
		}
	}
	return dp[bagWeight];
}


int main()
{
	vector<int> nums1 = {1, 1, 1, 1, 1};
	int target1 = 3;
	cout << findTargetSumWays(nums1, target1) << endl;

	vector<int> nums2 = {1};
	int target2 = 1;
	cout << findTargetSumWays(nums2, target2) << endl;

	return 0;
}