#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int wiggleMaxLength(vector<int>& nums)
{
	if (nums.size() == 1) return 1;

	// 记录前一对和当前对的差值
	int preDiff = 0;
	int curDiff = 0;
	int ans = 0;

	for (int i = 0; i < nums.size() - 1; i++) {
		curDiff = nums[i + 1] - nums[i];

		// 在 if 条件里更新 preDiff 而不是在 if 之外更新, 因为单调坡中有可能穿插平坡
		if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
			preDiff = curDiff;
			ans += 1;
		}
	}

	// 摆动序列长度等于差值个数加 1
	return ans + 1;
}


int main()
{
	vector<int> nums1 = {1, 7, 4, 9, 2, 5};
	cout << wiggleMaxLength(nums1) << endl;

	vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	cout << wiggleMaxLength(nums2) << endl;

	vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << wiggleMaxLength(nums3) << endl;

	return 0;
}