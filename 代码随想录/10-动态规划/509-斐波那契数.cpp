#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int fib(int n) 
{
	if (n <= 1) return n;

	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp[n];
}


int main()
{
	int n1 = 2;
	cout << fib(n1) << endl;

	int n2 = 3;
	cout << fib(n2) << endl;

	int n3 = 4;
	cout << fib(n3) << endl;

	return 0;
}