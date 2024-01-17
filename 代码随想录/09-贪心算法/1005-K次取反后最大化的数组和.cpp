#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int largestSumAfterKNegations(vector<int>& nums, int k) 
{
	int n = nums.size();

	// 记数组中小于 0 的元素个数为 h
	int h = 0;
	for (auto i: nums) {
		if (i < 0) h += 1;
	}

	// 排序
	sort(nums.begin(), nums.end(), less<int>());

	// 若 k 小于等于 h, 则选择从小到大的 k 个负数进行取反
	for (int i = 0; i < min(h, k); i++) {
		nums[i] = -nums[i];
	}
	// 若 k 大于 h, 选择所有 h 个负数取反后:
	// 1. (h - k) 为奇数, 相当于对绝对值最小的元素再取反
	// 2. (h - k) 为偶数, 相当于不再进行取反
	if (k > h && (k - h) % 2 != 0) {
		sort(nums.begin(), nums.end(), less<int>());
		nums[0] = -nums[0];
	}

	int sum = 0;
	for (auto i: nums) sum += i;
	return sum;
}


int main()
{
	vector<int> nums1 = {4, 2, 3};
	int k1 = 1;
	cout << largestSumAfterKNegations(nums1, k1) << endl;

	vector<int> nums2 = {3, -1, 0, 2};
	int k2 = 3;
	cout << largestSumAfterKNegations(nums2, k2) << endl;

	vector<int> nums3 = {2, -3, -1, 5, -4};
	int k3 = 2;
	cout << largestSumAfterKNegations(nums3, k3) << endl;

	return 0;
}