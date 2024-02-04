#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*一维数组解法*/
int robRange_v1(vector<int> nums)
{
	int n = nums.size();

	// dp[i] 表示从下标 0-i 的房屋最多可以偷窃到的金额
	vector<int> dp(n, 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);

	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[n - 1];
}


int rob_v1(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1) return nums[0];
	if (len == 2) return max(nums[0], nums[1]);

	// 计算区间 [0: n - 1)
	vector<int> sliced1(nums.begin(), nums.begin() + len - 1);  // 注意左闭右开
	int ans1 = robRange_v1(sliced1);

	// 计算区间 [1: n)
	vector<int> sliced2(nums.begin() + 1, nums.begin() + len);
	int ans2 = robRange_v1(sliced2);

	return max(ans1, ans2);
}


/*二维数组解法*/
int robRange_v2(vector<int> nums)
{
	int n = nums.size();

	// dp[i][0] 表示从下标 0-i 的房屋最多可以偷窃到的金额, 且当前不偷窃房屋 i
	// dp[i][1] 表示从下标 0-i 的房屋最多可以偷窃到的金额, 且当前偷窃房屋 i
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = nums[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + nums[i];
	}
	return max(dp[n - 1][0], dp[n - 1][1]);
}


int rob_v2(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1) return nums[0];

	// 计算区间 [0: n - 1)
	vector<int> sliced1(nums.begin(), nums.begin() + len - 1);  // 注意左闭右开
	int ans1 = robRange_v2(sliced1);

	// 计算区间 [1: n)
	vector<int> sliced2(nums.begin() + 1, nums.begin() + len);
	int ans2 = robRange_v2(sliced2);

	return max(ans1, ans2);
}



int main()
{	
	vector<int> nums1 = {2, 3, 2};
	cout << rob_v1(nums1) << endl;

	vector<int> nums2 = {1, 2, 3, 1};
	cout << rob_v1(nums2) << endl;

	vector<int> nums3 = {1, 2, 3};
	cout << rob_v2(nums3) << endl;

	return 0;
}