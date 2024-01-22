#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int climbStairs(int n) 
{
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp[n];
}


int main()
{
	int n1 = 2;
	cout << climbStairs(n1) << endl;

	int n2 = 3;
	cout << climbStairs(n2) << endl;

	return 0;
}