#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
	思路: 将数值作为 key, 将位置作为 value,
	通过 target - nums[i] 来寻找是否有匹配的数值
*/

vector<int> twoSum(vector<int>& nums, int target)
{
	// nums[i] -> i
	unordered_map<int, int> mp;

	for (int i = 0; i < nums.size(); i++) 
	{
		if (mp.find(target - nums[i]) == mp.end()) {
			mp[nums[i]] = i;
		}
		else {
			return {mp[target - nums[i]], i};
		}
	}
	return {-1, -1};
}


int main()
{
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	vector<int> ans = twoSum(nums, target);
	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}