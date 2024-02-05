#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	连续子序列: nums[l: r] 满足 0 <= l <= r < n (要求连续)
	nums[] = {1 3 5 4 7}
	dp[] = {1 2 3 1 2}
*/

int findLengthOfLCIS(vector<int>& nums) 
{
	int n = nums.size();
	int maxLength = INT_MIN;

	// dp[i] 表示 i 之前包括 i 的以 nums[i] 结尾的最长连续递增子序列的长度 (注意是结尾, 子序列必定包含 nums[i])
	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++) {
		// 由于是求连续子序列, 因此只需要比较相邻元素
		// 位置 i 的最长递增连续子序列等于位置 i - 1 的最长递增连续子序列 + 1
		if (nums[i - 1] < nums[i]) {
			dp[i] = dp[i - 1] + 1;
		}
	}

	for (auto i: dp) maxLength = max(maxLength, i);
	return maxLength;
}


int main()
{
	vector<int> nums1 = {1, 3, 5, 4, 7};
	cout << findLengthOfLCIS(nums1) << endl;

	vector<int> nums2 = {2, 2, 2, 2, 2};
	cout << findLengthOfLCIS(nums2) << endl;	

	return 0;
}