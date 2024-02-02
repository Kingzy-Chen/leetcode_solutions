#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int combinationSum4(vector<int>& nums, int target)
{
	int n = nums.size();
	
	// dp[j] 表示总和为 target 的元素排列数
	vector<unsigned long long> dp(target + 1, 0);  // unsigned long long 过样例

	// 由于是求解排列数, 因此先遍历容量再遍历物品
	dp[0] = 1;
	for (int j = 0; j <= target; j++) {  // 遍历容量
		for (int i = 0; i < n; i++) {  // 遍历物品
			if (j >= nums[i]) dp[j] += dp[j - nums[i]];  // 装满背包的方式
			else continue;
		}
	}
	return dp[target];
}


int main()
{
	vector<int> nums1 = {1, 2, 3};
	int target1 = 4;
	cout << combinationSum4(nums1, target1) << endl;

	vector<int> nums2 = {9};
	int target2 = 3;
	cout << combinationSum4(nums2, target2) << endl;

	return 0;
}