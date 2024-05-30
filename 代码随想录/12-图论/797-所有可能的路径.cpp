#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*DFS, 类似于回溯模板*/
vector<vector<int>> result;
vector<int> path;


void dfs(vector<vector<int>>& graph, int n, int src) 
{
	if (src == n - 1) {
		result.push_back(path);
		return;
	}

	for (int i = 0; i < graph[src].size(); i++) {
		path.push_back(graph[src][i]);
		dfs(graph, n, graph[src][i]);
		path.pop_back();
	}
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
	result.clear();
	path.clear();
	int n = graph.size();
	path.push_back(0);

	dfs(graph, n, 0);
	return result;
}


int main()
{
	vector<vector<int>> graph = {
		{4, 3, 1},
		{3, 2, 4},
		{3},
		{4},
		{}
	};
	vector<vector<int>> ans = allPathsSourceTarget(graph);

	for (auto p: ans) {
		for (auto i: p) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}