#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*解法 1: 设置当前覆盖范围和下一步覆盖范围进行判断*/
int jump_v1(vector<int> nums)
{
	int n = nums.size();
	int ans = 0;
	int curCover = 0;
	int nextCover = 0;

	for (int i = 0; i < nums.size(); i++) {
		nextCover = max(nextCover, i + nums[i]);

		// 一旦到达当前覆盖范围, 更新为下一步覆盖范围并且步数计数加 1
		if (i == curCover) {
			curCover = nextCover;
			ans += 1;
			if (nextCover >= n - 1) break;
		}
	}
	return ans;
}


/*解法 2: 利用数组记录到达的步数*/
int jump_v2(vector<int> nums)
{
	// 特判
	int n = nums.size();
	if (n == 1) return 0;

	// 数组元素 reach[i] 表示到达位置 i 所需要的最小步数
	vector<int> reach(n, 0);
	int cover = 0;

	for (int i = 0; i <= cover; i++) {
		// 下一步新扩展的覆盖范围到达步数加 1
		for (int j = cover + 1; j <= min(i + nums[i], n - 1); j++) reach[j] = reach[i] + 1;
		// 更新覆盖范围
		cover = max(cover, i + nums[i]);
		if (cover >= n - 1) break;
	}
	return reach[n - 1];
}


int main()
{
	vector<int> nums1 = {2, 3, 1, 1, 4};
	cout << jump_v1(nums1) << endl;

	vector<int> nums2 = {2, 3, 0, 1, 4};
	cout << jump_v2(nums2) << endl;

	return 0;
}