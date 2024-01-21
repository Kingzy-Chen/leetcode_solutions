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


int findMinArrowShots(vector<vector<int>>& points) 
{
	sort(points.begin(), points.end(), cmp);

	int n = points.size();
	int ans = 1;
	int end = points[0][1];

	for (int i = 1; i < n; i++) {
		// 若当前气球左边界小于等于 end, 则说明存在重叠, 更新 end
		if (points[i][0] <= end) {
			end = min(end, points[i][1]);  // 确定最小右边界
		}
		// 若不重叠, 则需要增加一支弓箭
		else {
			ans += 1;
			end = points[i][1];
		}
	}
	return ans;
}


int main()
{
	vector<vector<int>> points1 = {
		vector<int>{10, 16},
		vector<int>{2, 8},
		vector<int>{1, 6},
		vector<int>{7, 12}
	};
	cout << findMinArrowShots(points1) << endl;

	vector<vector<int>> points2 = {
		vector<int>{1, 2},
		vector<int>{3, 4},
		vector<int>{5, 6},
		vector<int>{7, 8}
	};
	cout << findMinArrowShots(points2) << endl;

	vector<vector<int>> points3 = {
		vector<int>{1, 2},
		vector<int>{2, 3},
		vector<int>{3, 4},
		vector<int>{4, 5}
	};
	cout << findMinArrowShots(points3) << endl;

	return 0;
}