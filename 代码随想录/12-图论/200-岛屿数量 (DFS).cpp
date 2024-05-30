#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	深度优先搜索模板 (类似于回溯):
	void DFS(参数) {
		if (终止条件) {
			... ... // 存放结果
			return;
		}

		for (选择: 本节点所连接的其他节点) {
			... ... // 处理节点
			backtracking(路径, 选择列表); // 递归
			... ... // 回溯, 撤销处理结果
		}
	}
*/

// 方向数组
vector<vector<int>> direction = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};  // 上下左右

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m) 
{
	// 边界条件
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	// 访问标记与可达陆地
	if (visited[x][y] == true || grid[x][y] == '0') return;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int x_ = x + direction[i][0];
		int y_ = y + direction[i][1];
		dfs(grid, visited, x_, y_, n, m);
	}
}


int numIslands(vector<vector<char>>& grid) 
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && grid[i][j] == '1') {
				dfs(grid, visited, i, j, n, m);
				ans += 1;
			}
		}
	}
	return ans;
}


int main()
{
	vector<vector<char>> grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	};

	int ans = numIslands(grid);
	cout << ans << endl;

	return 0;
}