#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int numTrees(int n) 
{
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	// dp[i] += dp[j - 1] * dp[i - j]
	// j - 1 为 j 作为头节点的左子树节点数量, i - j 为 j 作为头节点的右子树节点数量 
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += (dp[j - 1] * dp[i - j]);
		}
	}
	return dp[n];
}


int main()
{
	int n1 = 3;
	cout << numTrees(n1) << endl;

	int n2 = 1;
	cout << numTrees(n2) << endl;

	return 0;
}