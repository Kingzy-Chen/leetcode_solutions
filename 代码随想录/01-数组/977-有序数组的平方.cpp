#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/*左右指针法*/
vector<int> sortedSquares(vector<int>& nums)
{
	int n = nums.size();
	int left = 0;
	int right = n - 1;

	vector<int> ans(n, 0);
	int k = n - 1;

	while (left <= right) {
		// 因为原数组升序, 故平方后能达到最大的元素不是在最左边就是在最右边
		if (pow(nums[left], 2) < pow(nums[right], 2)) {
			ans[k--] = pow(nums[right--], 2);
		}
		else {
			ans[k--] = pow(nums[left++], 2);
		}
	}
	return ans;
}


int main()
{
	vector<int> nums = {-4, -1, 0, 3, 10};
	vector<int> ans = sortedSquares(nums);
	for (auto t: ans) cout << t << " ";
	cout << endl;

	return 0;
}