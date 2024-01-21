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

void printResult(vector<vector<int>> result)
{
	for (auto v: result) {
		cout << "[" << v[0] << "," << v[1] << "] ";
	}
	cout << endl;
}


// 自定义排序
bool cmp(vector<int>& A, vector<int>& B) 
{
	// 区间左边界从小到大排序
	return A[0] < B[0];
}


vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end(), cmp);
	vector<vector<int>> ans;

	int n = intervals.size();
	int start = intervals[0][0];
	int end = intervals[0][1];
	
	for (int i = 1; i < n; i++) {
		// 若区间左边界小于 end, 则说明存在重叠, 更新右边界 end
		if (intervals[i][0] <= end) {
			end = max(intervals[i][1], end);  // 确定最大右边界, 相当于合并重叠区间
		}
		// 若不重叠, 存放当前合并区间到结果集, 并更新 start 和 end, 相当于关注下一个区间
		else {
			ans.push_back({start, end});
			start = intervals[i][0];
			end = intervals[i][1];
		}
	}
	// 将最后一个区间加入结果集
	ans.push_back({start, end});
	return ans;
}


int main()
{
	vector<vector<int>> intervals1 = {
		vector<int>{1, 3},
		vector<int>{2, 6},
		vector<int>{8, 10},
		vector<int>{15, 18}
	};
	printResult(merge(intervals1));

	vector<vector<int>> intervals2 = {
		vector<int>{1, 4},
		vector<int>{4, 5}
	};
	printResult(merge(intervals2));

	return 0;
}