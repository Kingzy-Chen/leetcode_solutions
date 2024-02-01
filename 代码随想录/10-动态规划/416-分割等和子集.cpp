#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canPartition(vector<int>& nums) 
{
	// 计算数组总和
	int sum = 0;
	for (auto i: nums) sum += i;
	// 若总和为奇数则说明不可分割
	if (sum % 2 != 0) return false;

	// 尽量将数字凑到总和的一半, dp[j] 表示选取数字放入容量为 j 的背包所获得的最大数字和
	int bagWeight = sum / 2;
	int n = nums.size();
	vector<int> dp(bagWeight + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = bagWeight; j >= 0; j--) {
			if (j >= nums[i]) dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			else continue;
		}
	}
	return dp[bagWeight] == sum / 2;
}


int main()
{
	vector<int> nums1 = {1, 5, 11, 5};
	cout << canPartition(nums1) << endl;

	vector<int> nums2 = {1, 2, 3, 5};
	cout << canPartition(nums2) << endl;

	return 0;
}