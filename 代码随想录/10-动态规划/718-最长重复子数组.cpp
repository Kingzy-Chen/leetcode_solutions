#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	最长重复子数组 (要求连续)
	nums1[] = {1 2 3 2 1}
	nums2[] = {3 2 1 4 7}
	ans[] = {3 2 1}

	dp[] = 
	  B 3 2 1 4 7
	A 0 0 0 0 0 0
	1 0 0 0 1 0 0
	2 0 0 1 0 0 0
	3 0 1 0 0 0 0
	2 0 0 2 0 0 0
	1 0 0 0 3 0 0
*/

int findLength(vector<int>& nums1, vector<int>& nums2) 
{
	int n1 = nums1.size();
	int n2 = nums2.size();
	int maxLength = 0;

	// dp[i][j] 表示以下标 i - 1 为结尾的 A, 和以下标 j - 1 结尾的 B, 最长重复子数组的长度
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			// 遇到相同数字, 斜对角 + 1
			if (nums1[i - 1] == nums2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			maxLength = max(maxLength, dp[i][j]);
		}
	}
	return maxLength;
}


int main()
{
	vector<int> nums1 = {1, 2, 3, 2, 1};
	vector<int> nums2 = {3, 2, 1, 4, 7};
	cout << findLength(nums1, nums2) << endl;

	return 0;
}