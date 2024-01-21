#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	区间重叠问题模板:
	sort(intervals.begin(), intervals.end(), cmp); // 按照区间左边界从小到大排序
	int end = intervals[0][1];

	for (int i = 1; i < intervals.size(); i++) {
		// 存在重叠的情况
		if (intervals[i][0] <= end) {
			... ...                              // 统计结果
			end = max/min(end, intervals[i][1]); // 维护最小/最大右边界
		}
		// 非重叠的情况
		else {
			... ...                // 统计结果
			end = intervals[i][1]; // 直接将右边界替换为当前区间的右边界
		}
	}
*/

// 自定义排序
bool cmp(vector<int>& A, vector<int>& B) 
{
	// 区间左边界从小到大排序
	return A[0] < B[0];
}


int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end(), cmp);

	int n = intervals.size();
	int cnt = 0;
	int end = intervals[0][1];

	for (int i = 1; i < n; i++) {
		// 若区间左边界小于 end, 则说明存在重叠, 需要移除的区间数量加 1
		if (intervals[i][0] < end) {
			cnt += 1;
			end = min(end, intervals[i][1]);  // 确定最小右边界
		}
		// 若不重叠, 将 end 更新为当前区间的右边界
		else end = intervals[i][1];
	}
	return cnt;
}


int main()
{
	vector<vector<int>> intervals1 = {
		vector<int>{1, 2},
		vector<int>{2, 3},
		vector<int>{3, 4},
		vector<int>{1, 3}
	};
	cout << eraseOverlapIntervals(intervals1) << endl;

	vector<vector<int>> intervals2 = {
		vector<int>{1, 2},
		vector<int>{1, 2},
		vector<int>{1, 2}
	};
	cout << eraseOverlapIntervals(intervals2) << endl;

	vector<vector<int>> intervals3 = {
		vector<int>{1, 2},
		vector<int>{2, 3}
	};
	cout << eraseOverlapIntervals(intervals3) << endl;

	return 0;
}