#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
	priority_queue<Type, Container, Functional>: 优先级队列, 用于构造大顶堆/小顶堆
	+ Type: 数据类型
	+ Container: 容器类型, 用 vector<Type> 实现
	+ Functional: 自定义排序, 需要创建一个 class/struct 并实现 operator() 方法, 也可传入 less<Type>/greater<Type> (但不用加括号)

	top(): 返回堆顶元素
	pop()/push(): 弹出堆顶元素/向堆压入元素
*/

struct cmp {
public:
	bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
		return p1.second < p2.second;  // 在 sort() 中 left < right 是从小到大排序, 但在 priority_queue 中是创建大顶堆
	}
};

/*维护大顶堆*/
vector<int> topKFrequent(vector<int>& nums, int k) 
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
	unordered_map<int, int> num2cnt;  // nums[i] -> cnt

	for (auto i: nums) {
		num2cnt[i] += 1;
	}
	for (auto& kv: num2cnt) {
		que.push(make_pair(kv.first, kv.second));
	}

	vector<int> ans;
	while (k--) {
		ans.push_back(que.top().first);
		que.pop();
	}
	return ans;
}


int main()
{
	vector<int> nums1 = {1, 1, 1, 2, 2, 3};
	int k1 = 2;

	vector<int> ans1 = topKFrequent(nums1, k1);
	for (auto i: ans1) cout << i << " ";
	cout << endl;

	vector<int> nums2 = {1};
	int k2 = 1;

	vector<int> ans2 = topKFrequent(nums2, k2);
	for (auto i: ans2) cout << i << " ";
	cout << endl;

	return 0;
}