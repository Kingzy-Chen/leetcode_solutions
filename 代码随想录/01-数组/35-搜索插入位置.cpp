#include <iostream>
#include <vector>
using namespace std;


int searchInsert(vector<int>& nums, int target)
{
	int n = nums.size();
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (right - left) / 2 + left;

		if (target > nums[mid]) {
			left = mid + 1;
		}
		else if (target < nums[mid]) {
			right = mid - 1;
		}
		else return mid;
	}

	// 若目标值不存在于数组中, 则返回其被按顺序插入的位置
	return left;
}


int main()
{
	vector<int> nums1 = {1, 3, 5, 6};
	int target1 = 5;
	int ans1 = searchInsert(nums1, target1);
	cout << ans1 << endl;

	vector<int> nums2 = {1, 3, 5, 6};
	int target2 = 2;
	int ans2 = searchInsert(nums2, target2);
	cout << ans2 << endl;

	return 0;
}