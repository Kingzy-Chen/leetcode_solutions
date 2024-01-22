#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));

	// 起点或终点出现障碍物, 直接返回 0
	if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
	dp[0][0] = 1;

	for (int i = 1; i < m; i++) {
		if (!obstacleGrid[i][0]) dp[i][0] = dp[i - 1][0];
		else dp[i][0] = 0;
	}
	for (int j = 1; j < n; j++) {
		if (!obstacleGrid[0][j]) dp[0][j] = dp[0][j - 1];
		else dp[0][j] = 0; 
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (!obstacleGrid[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else dp[i][j] = 0;
		}
	}
	return dp[m - 1][n - 1];
}


int main()
{
	vector<vector<int>> obstacleGrid1 = {
		vector<int>{0, 0, 0},
		vector<int>{0, 1, 0},
		vector<int>{0, 0, 0}
	};
	cout << uniquePathsWithObstacles(obstacleGrid1) << endl;

	vector<vector<int>> obstacleGrid2 = {
		vector<int>{0, 1},
		vector<int>{0, 0}
	};
	cout << uniquePathsWithObstacles(obstacleGrid2) << endl;

	return 0;
}