#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	int ans = 0;

	// 计算后一天相对前一天的利润
	for (int i = 0; i < n - 1; i++) {
		// 计算大于 0 的利润总和
		int profit = prices[i + 1] - prices[i];
		if (profit > 0) ans += profit;
	}
	return ans;
}


int main()
{
	vector<int> prices1 = {7, 1, 5, 3, 6, 4};
	cout << maxProfit(prices1) << endl;

	vector<int> prices2 = {1, 2, 3, 4, 5};
	cout << maxProfit(prices2) << endl;

	vector<int> prices3 = {7, 6, 4, 3, 1};
	cout << maxProfit(prices3) << endl;

	return 0;
}