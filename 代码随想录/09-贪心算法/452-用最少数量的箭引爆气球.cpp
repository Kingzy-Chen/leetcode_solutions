#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 自定义排序
bool cmp(vector<int>& A, vector<int>& B) 
{
	// 区间左边界从小到大排序
	return A[0] < B[0];
}


int findMinArrowShots(vector<vector<int>>& points) 
{
	sort(points.begin(), points.end(), cmp);
	int end = points[0][1];
	int ans = 1;

	for (int i = 1; i < points.size(); i++) {
		// 若当前气球左边界小于等于 end, 即存在重叠, 则更新 end
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