#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> s(nums1.begin(), nums1.end());
	unordered_set<int> ans;

	for (auto i: nums2) {
		if (s.find(i) != s.end()) {
			ans.insert(i);
		}
	}
	return vector<int>(ans.begin(), ans.end());  // 可以通过 begin 和 end 直接将类型进行转换
}


int main()
{
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	vector<int> ans = intersection(nums1, nums2);

	for (auto t: ans) cout << t << " ";
	cout << endl;

	return 0;
}