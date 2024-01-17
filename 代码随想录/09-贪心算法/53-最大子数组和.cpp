#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSubArray(vector<int>& nums)
{
	// 记录当前连续子数组的和
	int curSum = 0;
	// 最大连续子数组和
	int maxSum = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		curSum += nums[i];
		maxSum = max(maxSum, curSum);  // 更新最大子数组和

		// 一旦子数组和小于 0, 说明可以从当前位置的下一位开始重新计算子数组和
		if (curSum < 0) curSum = 0;
	}
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