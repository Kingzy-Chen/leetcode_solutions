#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
	思路: 类似于 1-两数之和,
	但需要两两数组来遍历, 将数值总和作为 key, 将数值总和出现的次数作为 value
*/

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
{
	unordered_map<int, int> mp;
	int n = nums1.size();
	int ans = 0;

	for (auto a: nums1) {
		for (auto b: nums2) {
			mp[a + b] += 1;
		}
	}
	for (auto c: nums3) {
		for (auto d: nums4) {
			ans += mp[0 - c - d];
		}
	}
	return ans;
}


int main()
{
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {-2, -1};
	vector<int> nums3 = {-1, 2};
	vector<int> nums4 = {0, 2};

	int ans = fourSumCount(nums1, nums2, nums3, nums4);
	cout << ans << endl;

	return 0;
}