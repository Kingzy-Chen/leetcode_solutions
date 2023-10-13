#include <iostream>
#include <vector>
using namespace std;


/*滑动窗口法*/
int minSubArrayLen_v1(int target, vector<int>& nums)
{
	int n = nums.size();
	int slow = 0;
	int fast = 0;

	int minLen = INT_MAX;
	int sumVal = nums[0];

	while (slow < n && fast < n && slow <= fast) 
	{
		// 当 sumVal 小于 target 时, 移动 fast
		if (sumVal < target) {
			fast++;
			if (fast < n) sumVal += nums[fast]; // 注意 fast 不要越界
		}
		// 当 sumVal 大于等于 target 时, 移动 slow 并更新 minLen
		else {
			minLen = min(minLen, fast - slow + 1);
			sumVal -= nums[slow];
			slow++;
		}
	}

	// 若 minLen 不更新, 则说明无法找到满足条件的子序列
	if (minLen == INT_MAX) return 0;
	else return minLen;
}


/*滑动窗口法*/
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
	int target_1 = 7;
	vector<int> nums_1 = {2, 3, 1, 2, 4, 3};
	int ans_1 = minSubArrayLen_v1(target_1, nums_1);
	cout << ans_1 << endl;

	int target_2 = 4;
	vector<int> nums_2 = {1, 4, 4};
	int ans_2 = minSubArrayLen_v2(target_2, nums_2);
	cout << ans_2 << endl;

	return 0;
}