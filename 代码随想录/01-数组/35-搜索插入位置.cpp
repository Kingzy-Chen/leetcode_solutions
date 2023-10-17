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
	vector<int> nums_1 = {1, 3, 5, 6};
	int target_1 = 5;
	int ans_1 = searchInsert(nums_1, target_1);
	cout << ans_1 << endl;

	vector<int> nums_2 = {1, 3, 5, 6};
	int target_2 = 2;
	int ans_2 = searchInsert(nums_2, target_2);
	cout << ans_2 << endl;

	return 0;
}