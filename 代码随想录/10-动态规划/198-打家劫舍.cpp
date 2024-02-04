#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*一维数组解法*/
int rob_v1(vector<int>& nums)
{
	int n = nums.size();
	if (n == 1) return nums[0];

	// dp[i] 表示从下标 0-i 的房屋最多可以偷窃到的金额
	vector<int> dp(n, 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);

	for (int i = 2; i < n; i++) {
		// 若偷窃当前下标为 i 的房屋, 则无法偷窃下标为 i - 1 的房屋
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[n - 1];
}


/*二维数组解法*/
int rob_v2(vector<int>& nums)
{
	int n = nums.size();

	// dp[i][0] 表示从下标 0-i 的房屋最多可以偷窃到的金额, 且当前不偷窃房屋 i
	// dp[i][1] 表示从下标 0-i 的房屋最多可以偷窃到的金额, 且当前偷窃房屋 i
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = nums[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);  // 若不偷窃当前房屋 i, 则偷窃或不偷窃房屋 i - 1 均可
		dp[i][1] = dp[i - 1][0] + nums[i];  // 若偷窃当前房屋 i, 则不可能偷窃房屋 i - 1
	}
	return max(dp[n - 1][0], dp[n - 1][1]);
}


int main()
{
	vector<int> nums1 = {1, 2, 3, 1};
	cout << rob_v1(nums1) << endl;

	vector<int> nums2 = {2, 7, 9, 3, 1};
	cout << rob_v2(nums2) << endl;

	return 0;
}