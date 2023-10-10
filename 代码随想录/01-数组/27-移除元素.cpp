#include <iostream>
#include <vector>
using namespace std;


/*左右指针法*/
int removeElement_v1(vector<int>& nums, int val)
{
	int n = nums.size();
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		// 找到最右边不等于 val 的元素
		while (left <= right && nums[right] == val) {
			right--;
		}
		// 找到最左边等于 val 的元素
		while (left <= right && nums[left] != val) {
			left++;
		}
		// 用右边元素覆盖左边元素
		if (left <= right) {
			nums[left] = nums[right];
			left++;
			right--;
		}
	}

	// 最终 left 左边均为数组剩余元素
	return left;
}


/*快慢指针法*/
int removeElement_v2(vector<int>& nums, int val)
{
	int n = nums.size();
	int slow = 0;
	int fast = 0;

	for (fast = 0; fast < n; fast++) {
		// 将快指针遇到的非 val 元素覆盖慢指针元素
		if (nums[fast] != val) {
			nums[slow] = nums[fast];
			slow++;
		}
	}

	// 最终 slow 左边均为数组剩余元素
	return slow;
}


int main()
{
	vector<int> nums_1 = {0, 1, 2, 2, 3, 0, 4, 2};
	int val_1 = 2;
	int ans_1 = removeElement_v1(nums_1, val_1);

	cout << ans_1 << endl;
	for (int i = 0; i < ans_1; i++) cout << nums_1[i] << " ";
	cout << endl;

	vector<int> nums_2 = {3, 2, 2, 3};
	int val_2 = 3;
	int ans_2 = removeElement_v2(nums_2, val_2);

	cout << ans_2 << endl;
	for (int i = 0; i < ans_2; i++) cout << nums_2[i] << " ";
	cout << endl;

	return 0;
}