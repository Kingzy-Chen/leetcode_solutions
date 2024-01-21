#include <iostream>
#include <vector>
using namespace std;

/*
	二分查找模板:
	左闭右开区间写法: left = 0, right = n, while (left < right), right = mid;
	左闭右闭区间写法: left = 0, right = n - 1, while (left <= right), right = mid - 1;
	建议联想到数组只有一个元素的情况来判断使用 < 还是 <=
*/

int search(vector<int>& nums, int target)
{
	int n = nums.size();
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (right - left) / 2 + left;  // 防止溢出, 等同于 (left + right) / 2

		if (nums[mid] > target) {
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else return mid;
	}
	return -1;
}


int main()
{
	vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
	int target1 = 9;
	cout << search(nums1, target1) << endl;

	vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
	int target2 = 2;
	cout << search(nums2, target2) << endl;

	return 0;
}