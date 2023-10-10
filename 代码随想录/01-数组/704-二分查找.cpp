#include <iostream>
#include <vector>
using namespace std;

/*
	左闭右开区间写法: right = n, while (left < right), right = mid;
	左闭右闭区间写法: right = n - 1, while (left <= right), right = mid - 1;
	建议联想到 nums 只有一个元素的情况
*/

int search(vector<int>& nums, int target)
{
	int n = nums.size();
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

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
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 9;
	int ans = search(nums, target);
	cout << ans << endl;
}