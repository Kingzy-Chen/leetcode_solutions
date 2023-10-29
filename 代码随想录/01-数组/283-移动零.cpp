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
	vector<int> nums = {0, 1, 0, 3, 12};
	moveZeroes(nums);

	for (auto i: nums) cout << i << " ";
	cout << endl;

	return 0;
}