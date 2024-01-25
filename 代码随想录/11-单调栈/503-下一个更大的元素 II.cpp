#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> nextGreaterElements(vector<int>& nums) 
{
	// 维护单调递增的双向队列, 队列保存数组元素的下标
	deque<int> que;
	que.push_back(0);

	int n = nums.size();
	vector<int> ans(n, -1);

	// 遍历第一遍 nums 数组
	for (int i = 1; i < n; i++) {
		while (!que.empty() && nums[i] > nums[que.back()]) {
			ans[que.back()] = nums[i];
			que.pop_back();
		}
		que.push_back(i);
	}

	// 遍历第二遍 nums 数组, 直到队列的队头元素
	for (int i = 0; i <= que.front(); i++) {
		while (!que.empty() && nums[i] > nums[que.back()]) {
			ans[que.back()] = nums[i];
			que.pop_back();
		}
		que.push_back(i);
	}
	return ans;
}


int main()
{
	vector<int> nums1 = {1, 2, 1};
	vector<int> ans1 = nextGreaterElements(nums1);

	for (auto i: ans1) cout << i << " ";
	cout << endl;

	vector<int> nums2 = {1, 2, 3, 4, 3};
	vector<int> ans2 = nextGreaterElements(nums2);

	for (auto i: ans2) cout << i << " ";
	cout << endl;

	return 0;
}