#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	回溯算法模板:
	void backtracking(参数) {
		if (终止条件) {
			... ... // 存放结果
			return;
		}

		for (选择: 本层集合中元素 (树中节点孩子的数量就是集合的大小)) {
			... ... // 处理节点
			backtracking(路径, 选择列表); // 递归
			... ... // 回溯, 撤销处理结果
		}
	}
*/

// 打印结果
void printResult(vector<string> result)
{
	for (auto s: result) cout << s << " ";
	cout << endl << endl;
}


vector<vector<string>> path;


// 由于是求字典序最小的一条路径, 所以回溯函数用 bool 类型返回
bool backtracking(vector<vector<string>>& tickets, vector<bool>& used)
{
	if (path.size() == tickets.size()) {
		return true;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (path.size() == 0 && tickets[i][0] != "JFK") continue;  // 要求起点为 JFK
		if (path.size() > 0 && tickets[i][0] != path.back()[1]) continue;  // 要求两机票的中继节点相同, 例如 [A, B] [B, C] 要求 B 相同
		if (used[i] == true) continue;  // 要求机票未被使用

		// 剪枝优化, 排序后利用 used 数组对机票进行去重
		if (i > 0 && tickets[i] == tickets[i - 1] && used[i - 1] == false) continue;

		path.push_back(tickets[i]);
		used[i] = true;
		if (backtracking(tickets, used)) return true;  // 只要找到一个符合条件的路径, 立刻返回
		used[i] = false;
		path.pop_back();
	}
	return false;
}


// 将机票序列转换为路径序列, 例如 [A, B] [B, C] -> [A, B, C]
vector<string> transform_path()
{
	vector<string> result;

	for (int i = 0; i < path.size(); i++) {
		if (i == 0) result.push_back(path[i][0]);
		result.push_back(path[i][1]);
	}
	return result;
}


// 对机票进行字典序排列
bool cmp(vector<string>& A, vector<string>& B)
{
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == B[i]) continue;
		return A[i] < B[i];
	}
	return false;
}


vector<string> findItinerary(vector<vector<string>>& tickets) 
{
	path.clear();
	vector<bool> used(tickets.size(), false);
	sort(tickets.begin(), tickets.end(), cmp);  // 字典序排序

	backtracking(tickets, used);
	vector<string> result = transform_path();
	return result;
}


int main()
{
	vector<vector<string>> tickets1 = {
		vector<string>{"MUC", "LHR"},
		vector<string>{"JFK", "MUC"},
		vector<string>{"SFO", "SJC"},
		vector<string>{"LHR", "SFO"},
	};
	printResult(findItinerary(tickets1));

	vector<vector<string>> tickets2 = {
		vector<string>{"JFK", "SFO"},
		vector<string>{"JFK", "ATL"},
		vector<string>{"SFO", "ATL"},
		vector<string>{"ATL", "JFK"},
		vector<string>{"ATL", "SFO"},
	};
	printResult(findItinerary(tickets2));

	return 0;
}