#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int removeDuplicates(vector<int>& nums) 
{
	int n = nums.size();
	int slow = 0;
	int fast = 0;
	unordered_set<int> s;

	for (fast = 0; fast < n; fast++) 
	{
		if (s.find(nums[fast]) == s.end()) 
		{
			nums[slow] = nums[fast];
			slow++;
			s.insert(nums[fast]);
		}
	}
	return slow;
}


int main()
{
	vector<int> nums1 = {1, 1, 2};
	int ans1 = removeDuplicates(nums1);
	for (int i = 0; i < ans1; i++) cout << nums1[i] << " ";
	cout << endl;

	vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	int ans2 = removeDuplicates(nums2);
	for (int i = 0; i < ans2; i++) cout << nums2[i] << " ";
	cout << endl;

	return 0;
}