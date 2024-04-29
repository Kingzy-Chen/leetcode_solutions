#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/*单调栈法, 思路类似于 42-接雨水, 但单调递减栈替换为单调递增栈*/
int largestRectangleArea(vector<int>& heights) 
{
	// 由于第一个柱子和最后一个柱子要纳入考虑, 因此在数组前后补 0
	heights.insert(heights.begin(), 0);
	heights.push_back(0);

	int n = heights.size();
	int ans = 0;

	// 维护单调栈内柱子高度递增
	stack<int> stk;
	stk.push(0);

	for (int i = 1; i < n; i++) {
		// 若当前柱子高度大于栈顶柱子高度, 直接压入单调栈
		if (heights[i] > heights[stk.top()]) {
			stk.push(i);
		}
		// 若当前柱子高度等于栈顶柱子高度, 推出栈顶柱子, 压入当前柱子
		else if (heights[i] == heights[stk.top()]) {
			stk.pop();
			stk.push(i);
		}
		// 若当前柱子高度小于栈顶柱子高度
		else {
			while (!stk.empty() && heights[i] < heights[stk.top()]) {
				// 推出栈顶柱子, 将其作为中央柱子
				int mid = stk.top();
				stk.pop();

				// 若此时单调栈非空, 则中央柱子作为候选区域的高度
				if (!stk.empty()) {
					int h = heights[mid];
					int w = i - stk.top() - 1;
					ans = max(ans, h * w);
				}
			}
			stk.push(i);
		}
	}

	return ans;
}


int main()
{
	vector<int> heights1 = {2, 1, 5, 6, 2, 3};
	cout << largestRectangleArea(heights1) << endl;

	vector<int> heights2 = {2, 4};
	cout << largestRectangleArea(heights2) << endl;

	return 0;
}