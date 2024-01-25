#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
	单调栈模板:
	stack<int> stk;
	stk.push(0);

	for (int i = 1; i < nums.size(); i++) {
		// 保持栈内元素从大到小排列 (单调栈保存数组元素的下标)
		while (!stk.empty() && nums[i] > nums[stk.top()]) {
			... ... // 处理逻辑
			stk.pop();
		}
		stk.push(i);
	}
*/

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
	stack<int> stk;
	stk.push(0);

	int n = temperatures.size();
	vector<int> ans(n, 0);

	for (int i = 1; i < n; i++) {
		while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
			ans[stk.top()] = i - stk.top();
			stk.pop();
		}
		stk.push(i);
	}
	return ans;
}


int main()
{
	vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> ans1 = dailyTemperatures(temperatures1);

	for (auto i: ans1) cout << i << " ";
	cout << endl;

	vector<int> temperatures2 = {30, 40, 50, 60};
	vector<int> ans2 = dailyTemperatures(temperatures2);

	for (auto i: ans2) cout << i << " ";
	cout << endl;

	return 0;
}