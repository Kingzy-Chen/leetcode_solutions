#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	思路: 单循环+头尾双指针
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1;
		int right = n - 1;
	}
*/

vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end(), less<int>());  // 升序排序

	int n = nums.size();
	int left = 0;
	int right = 0;

	for (int i = 0; i < n - 2; i++) 
	{
		// 剪枝, 若 nums[i] 大于 0, 则之后的元素无论如何也无法组成和为 0 的三元组, 因为已经升序排列
		if (nums[i] > 0) break;
		// 对 nums[i] 去重
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		left = i + 1;
		right = n - 1;

		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] > 0) right--;  // 若三元组和大于 0, 则左移 right 指针
			else if (nums[i] + nums[left] + nums[right] < 0) left++;  // 若三元组和小于 0, 则右移 left 指针
			else 
			{
				ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
				while (left < right && nums[right] == nums[right - 1]) right--;  // 对 nums[right] 去重
				while (left < right && nums[left] == nums[left + 1]) left++;     // 对 nums[left] 去重
				left++;
				right--;  // 若三元组和等于 0, 则同时移动 left 和 right 指针
			}
		}
	}
	return ans;
}


int main()
{
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> ans = threeSum(nums);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}