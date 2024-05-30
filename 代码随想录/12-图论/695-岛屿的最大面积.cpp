#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方向数组
vector<vector<int>> direction = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};  // 上下左右
// 岛屿面积
int area = 0;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m)
{
	// 访问标记与可达陆地
	if (grid[x][y] == 0 || visited[x][y] == true) return;

	area += 1;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int x_ = x + direction[i][0];
		int y_ = y + direction[i][1];
		// 边界条件
		if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) continue;
		dfs(grid, visited, x_, y_, n, m);
	}
}


int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int maxArea = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == 1) {
				area = 0;
				dfs(grid, visited, i, j, n, m);
				maxArea = max(maxArea, area);
			}
		}
	}
	return maxArea;
}


int main()
{
	vector<vector<int>> grid = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
	};
	
	int maxArea = maxAreaOfIsland(grid);
	cout << maxArea << endl;

	return 0;
}