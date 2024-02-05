#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	子序列: 删除或不删除数组中的元素而不改变其余元素的顺序 (不要求连续)
	nums[] = {10 9 2 5 3 7 101 18}
	dp[] = {1 1 1 2 2 3 4 4}
*/

int lengthOfLIS(vector<int>& nums) 
{
	int n = nums.size();
	int maxLength = INT_MIN;

	// dp[i] 表示 i 之前 (包括 i) 的以 nums[i] 结尾的最长递增子序列的长度 (注意是结尾, 子序列必定包含 nums[i])
	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// 位置 i 的最长递增子序列等于 j 从 0 到 i - 1 各个位置的最长递增子序列 + 1 的最大值
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (auto i: dp) maxLength = max(maxLength, i);
	return maxLength;
}


int main()
{
	vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << lengthOfLIS(nums1) << endl;

	vector<int> nums2 = {0, 1, 0, 3, 2, 3};
	cout << lengthOfLIS(nums2) << endl;

	vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
	cout << lengthOfLIS(nums3) << endl;	

	return 0;
}