#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	广度优先搜索模板 (类似于二叉树层序遍历):
	void bfs(参数) {
		queue<...> que;  // 创建队列
		que.push(...);   // 起点加入队列

		while (!que.empty()) {
			que.pop();
			... ... // 处理节点

			for (选择: 本节点所连接的其他节点) {
				que.push(...); // 新节点加入队列
			}
		}
	}
*/

// 方向数组
vector<vector<int>> direction = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};  // 上下左右

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m) 
{
	queue<vector<int>> que;
	que.push({x, y});

	while (!que.empty()) {
		auto pos = que.front();
		que.pop();

		int cur_x = pos[0];
		int cur_y = pos[1];
		// visited[cur_x][cur_y] = true;  // 若在循环外添加访问标记, 会超时

		for (int i = 0; i < 4; i++) {
			int x_ = cur_x + direction[i][0];
			int y_ = cur_y + direction[i][1];

			// 边界条件
			if (x_ < 0 || x_ >= n) continue;
			if (y_ < 0 || y_ >= m) continue;
			// 访问标记与可达陆地
			if (visited[x_][y_] == true || grid[x_][y_] == '0') continue;

			que.push({x_, y_});
			visited[x_][y_] = true;  // 在循环内添加访问标记, 防止超时
		}
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
				bfs(grid, visited, i, j, n, m);
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