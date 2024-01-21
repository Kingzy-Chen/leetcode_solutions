#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	int n = gas.size();

	// rest[i] 表示第 i 天剩下的油量
	vector<int> rest(n, 0);
	for (int i = 0; i < n; i++) rest[i] = gas[i] - cost[i];

	// 从某位置开始能够跑一圈的条件是 rest 数组从该位置开始的前缀和始终 >= 0
	int totalSum = 0;
	int curSum = 0;
	int startIdx = 0;

	for (int i = 0; i < n; i++) {
		totalSum += rest[i];
		curSum += rest[i];
		// 若到达位置 i 时的当前前缀和小于 0, 则说明起点一定在 i 之后
		if (curSum < 0) {curSum = 0; startIdx = i + 1;}
	}
	// 若 rest 数组总和小于 0, 则说明油量无法满足行程
	if (totalSum < 0) return -1;
	else return startIdx;
}


int main()
{
	vector<int> gas1 = {1, 2, 3, 4, 5};
	vector<int> cost1 = {3, 4, 5, 1, 2};
	cout << canCompleteCircuit(gas1, cost1) << endl;

	vector<int> gas2 = {2, 3, 4};
	vector<int> cost2 = {3, 4, 3};
	cout << canCompleteCircuit(gas2, cost2) << endl;

	return 0;
}