#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canJump(vector<int>& nums)
{
	// 特判
	int n = nums.size();
	if (n == 1) return true;

	// 不断更新覆盖范围
	int cover = 0;
	// 注意是小于等于 cover
	for (int i = 0; i <= cover; i++) {
		cover = max(cover, i + nums[i]);
		if (cover >= n - 1) return true;  // 可达到终点
	}
	return false;
}


int main()
{
	vector<int> nums1 = {2, 3, 1, 1, 4};
	cout << canJump(nums1) << endl;

	vector<int> nums2 = {3, 2, 1, 0, 4};
	cout << canJump(nums2) << endl;

	return 0;
}