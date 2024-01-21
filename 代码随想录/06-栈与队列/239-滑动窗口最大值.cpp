#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	deque: 双向队列
	push_front()/push_back(): 向队头/队尾添加元素
	pop_front()/pop_back(): 弹出队头/队尾元素
*/

// 添加新元素时, 先移除队尾中更小的元素, 从而维护单调队列递减
void push(deque<int>& que, int x)
{
	while (!que.empty() && que.back() < x) {
		que.pop_back();
	}
	que.push_back(x);
}


// 检查滑动窗口最左侧是否等于队头元素, 如相等则弹出队头元素
void pop(deque<int>& que, int x)
{
	if (!que.empty() && que.front() == x) {
		que.pop_front();
	}
}


/*维护单调队列*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	deque<int> que;  // 双向队列
	vector<int> ans;

	// 将前 k 个元素放入单调队列
	for (int i = 0; i < k; i++) {
		push(que, nums[i]);
	}
	// 队头元素为当前滑动窗口内的最大值
	ans.push_back(que.front());

	for (int i = k; i < nums.size(); i++) {
		// 移除离开滑动窗口范围的元素
		pop(que, nums[i - k]);
		// 添加新元素, 同时维护单调递减队列
		push(que, nums[i]);
		ans.push_back(que.front());
	}
	return ans;
}


int main()
{
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;

	vector<int> ans = maxSlidingWindow(nums, k);
	for (auto i: ans) cout << i << " ";
	cout << endl;

	return 0;
}