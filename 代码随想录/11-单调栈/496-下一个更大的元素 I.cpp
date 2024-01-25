#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{

	// nums2 数组元素 -> nums2 中下一个更大的元素
	unordered_map<int, int> nextGreater;
	
	// 单调栈保存 nums2 的数组元素
	stack<int> stk;
	stk.push(nums2[0]);

	for (int i = 1; i < nums2.size(); i++) {
		while (!stk.empty() && nums2[i] > stk.top()) {
			nextGreater[stk.top()] = nums2[i];
			stk.pop();
		}
		stk.push(nums2[i]);
	}

	vector<int> ans;
	for (auto i: nums1) {
		if (nextGreater.find(i) == nextGreater.end()) ans.push_back(-1);
		else ans.push_back(nextGreater[i]);
	}
	return ans;
}


int main()
{
	vector<int> nums1 = {4, 1, 2};
	vector<int> nums2 = {1, 3, 4, 2};

	vector<int> ans = nextGreaterElement(nums1, nums2);
	for (auto i: ans) cout << i << " ";
	cout << endl;

	return 0;
}