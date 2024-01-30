#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	双循环+头尾双指针模板:
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2; j++) {
			int left = j + 1;
			int right = n - 1;

			while (left < right) {
				... ...
			}
		}
	}
	类似于 15-三数之和
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end(), less<int>());  // 升序排序

	int n = nums.size();
	int left = 0;
	int right = 0;

	for (int i = 0; i < n - 3; i++)
	{
		// 剪枝, 若 nums[i] 大于 target 且为正数, 则与之后的元素相加必定大于 target
		if (nums[i] > target && nums[i] >= 0) break;
		// 对 nums[i] 去重
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		for (int j = i + 1; j < n - 2; j++)
		{
			// 剪枝, 若 nums[i] + nums[j] 大于 target 且 nums[j] 为正数, 则与之后的元素相加必定大于 target
			if (nums[i] + nums[j] > target && nums[j] >= 0) break;
			// 对 nums[j] 去重
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;

			left = j + 1;
			right = n - 1;

			while (left < right)
			{
				if ((long long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;  // long long 防止溢出
				else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
				else
				{
					ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
					while (left < right && nums[right] == nums[right - 1]) right--;  // 对 nums[right] 去重
					while (left < right && nums[left] == nums[left + 1]) left++;     // 对 nums[left] 去重
					right--;
					left++;
				}
			}
		}
	}
	return ans;
}


int main()
{
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<vector<int>> ans = fourSum(nums, target);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}