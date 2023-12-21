#include <iostream>
#include <vector>
using namespace std;

/*
	思路: 滑动窗口, 左闭右开区间 [left, right)
	int left = 0;
	int right = 0;

	while (right < n) {
		// 更新窗口内元素
		...
		// 移动右指针
		right++;

		// 判断窗口是否需要收缩
		while (window needs shrink) {
			// 更新窗口内元素
			...
			// 移动左指针
			left++;
		}
	}
*/

int minSubArrayLen_v1(int target, vector<int>& nums)
{
	int n = nums.size();
	int left = 0;
	int right = 0;

	int minLen = INT_MAX;
	int sumVal = 0;

	while (right < n) {
		// 更新窗口内元素
		sumVal += nums[right];
		// 移动右指针
		right++;

		// 当 sumVal 大于等于 target 时, 移动 left 并更新 minLen
		while (sumVal >= target) {
			// 左闭右开区间
			minLen = min(minLen, right - left);
			// 更新窗口内元素
			sumVal -= nums[left];
			// 移动左指针
			left++;
		}
	}

	// 若 minLen 不更新, 则说明无法找到满足条件的子序列
	if (minLen == INT_MAX) return 0;
	else return minLen;
}


int minSubArrayLen_v2(int target, vector<int>& nums)
{
	int n = nums.size();
	int sumVal = 0;
	int minLen = INT_MAX;

	// 子序列起点 i
	for (int i = 0; i < n; i++) {
		sumVal = 0;

		// 子序列终点 j
		for (int j = i; j < n; j++) {
			sumVal += nums[j];

			// 一旦子序列和大于等于 target, 更新 minLen
			if (sumVal >= target) {
				// 左闭右闭区间
				minLen = min(minLen, j - i + 1);
				// 直接跳出循环, 因为求的是长度最小子序列
				break;
			}
		}
	}

	// 若 minLen 不更新, 则说明无法找到满足条件的子数组
	if (minLen == INT_MAX) return 0;
	else return minLen;
}


int main()
{
	int target1 = 7;
	vector<int> nums1 = {2, 3, 1, 2, 4, 3};
	int ans1 = minSubArrayLen_v1(target1, nums1);
	cout << ans1 << endl;

	int target2 = 4;
	vector<int> nums2 = {1, 4, 4};
	int ans2 = minSubArrayLen_v2(target2, nums2);
	cout << ans2 << endl;

	return 0;
}