#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


// 原理与 1143-最长公共子序列 相同
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
{
	int n1 = nums1.size();
	int n2 = nums2.size();
	int maxLength = 0;
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (nums1[i - 1] == nums2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			maxLength = max(maxLength, dp[i][j]);
		}
	}
	return maxLength;
}


int main()
{
	vector<int> nums1 = {1, 4, 2};
	vector<int> nums2 = {1, 2, 4};
	cout << maxUncrossedLines(nums1, nums2) << endl;

	return 0;
}