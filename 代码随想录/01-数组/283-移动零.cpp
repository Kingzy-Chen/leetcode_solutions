#include <iostream>
#include <vector>
using namespace std;


void moveZeroes(vector<int>& nums) 
{
	int n = nums.size();
	int slow = 0;
	int fast = 0;

	for (fast = 0; fast < n; fast++) {
		if (nums[fast] != 0) {
			nums[slow] = nums[fast];
			slow++;
		}
	}
	while (slow < n) {
		nums[slow++] = 0;
	}
}


int main()
{
	vector<int> nums1 = {0, 1, 0, 3, 12};
	moveZeroes(nums1);
	for (auto i: nums1) cout << i << " ";
	cout << endl;

	vector<int> nums2 = {0};
	moveZeroes(nums2);
	for (auto i: nums2) cout << i << " ";
	cout << endl;

	return 0;
}