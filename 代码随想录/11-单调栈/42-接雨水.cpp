#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/*解法 1: 按列计算, 暴力法*/
int trap_v1(vector<int>& height)
{
	int n = height.size();
	int ans = 0;

	for (int i = 0; i < n; i++) 
	{
		// 第一个和最后一个柱子不接水
		if (i == 0 || i == n - 1) continue;

		// 对于位置 i, 寻找其左侧和右侧柱子的最大高度
		int rHeight = height[i];
		int lHeight = height[i];

		for (int r = i + 1; r < n; r++) {
			rHeight = max(rHeight, height[r]);
		}
		for (int l = i - 1; l >= 0; l--) {
			lHeight = max(lHeight, height[l]);
		}

		int h = min(lHeight, rHeight) - height[i];
		if (h > 0) ans += h;
	}

	return ans;
}


/*解法 2: 按列计算, 双指针法*/
int trap_v2(vector<int>& height)
{
	int n = height.size();
	if (n <= 2) return 0;

	// 计算每个位置的左侧和右侧柱子的最大高度, 提前保存在数组里
	vector<int> maxLeft(n, 0);
	vector<int> maxRight(n, 0);

	maxLeft[0] = height[0];
	for (int i = 1; i < n; i++) {
		maxLeft[i] = max(maxLeft[i - 1], height[i]);
	}

	maxRight[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		maxRight[i] = max(maxRight[i + 1], height[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (min(maxLeft[i], maxRight[i]) - height[i]);
	}

	return ans;
}


/*解法 3: 按行计算, 单调栈法*/
int trap_v3(vector<int>& height)
{
	int n = height.size();
	int ans = 0;

	// 维护单调栈内柱子高度递减
	stack<int> stk;
	stk.push(0);

	for (int i = 1; i < n; i++) {
		// 若当前柱子高度低于栈顶柱子高度, 直接压入单调栈
		if (height[i] < height[stk.top()]) {
			stk.push(i);
		}
		// 若当前柱子高度等于栈顶柱子高度, 推出栈顶柱子, 压入当前柱子
		else if (height[i] == height[stk.top()]) {
			stk.pop();
			stk.push(i);
		}
		// 若当前柱子高度大于栈顶柱子高度
		else {
			while (!stk.empty() && height[i] > height[stk.top()]) {
				// 推出栈顶柱子, 将其作为凹槽中央柱子
				int mid = stk.top();
				stk.pop();

				// 若此时单调栈非空, 则栈顶柱子作为凹槽左边界, 当前柱子作为凹槽右边界
				if (!stk.empty()) {
					int h = min(height[i], height[stk.top()]) - height[mid];
					int w = i - stk.top() - 1;
					ans += (h * w);
				}
			}
			stk.push(i);
		}
	}

	return ans;
}


int main()
{
	vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trap_v1(height1) << endl;
	cout << trap_v2(height1) << endl;

	vector<int> height2 = {4, 2, 0, 3, 2, 5};
	cout << trap_v3(height2) << endl;

	return 0;
}