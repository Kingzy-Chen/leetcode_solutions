#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSubArray(vector<int>& nums) 
{
	int n = nums.size();
	int maxSum = INT_MIN;

	// dp[i] 表示 i 之前 (包括 i) 的以 nums[i] 结尾的最大连续子序列和 (注意是结尾, 子序列必定包含 nums[i])
	vector<int> dp(n, 0);
	dp[0] = nums[0];

	for (int i = 1; i < n; i++) {
		// 检查 nums[i] 添加到 i - 1 位置的最大连续子序列时, 总和是否会下降
		if (dp[i - 1] < 0) dp[i] = nums[i];
		else dp[i] = dp[i - 1] + nums[i];
	}

	for (auto i: dp) maxSum = max(maxSum, i);
	return maxSum;
}


int main()
{
	vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(nums1) << endl;

	vector<int> nums2 = {5, 4, -1, 7, 8};
	cout << maxSubArray(nums2) << endl;

	return 0;
}