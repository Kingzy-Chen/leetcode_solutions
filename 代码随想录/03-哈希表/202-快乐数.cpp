#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;


bool isHappy(int n) 
{
	unordered_set<int> s;  // 存储出现过的结果
	int N = n;
	int a = 0;
	int sum = 0;

	while (N != 1) {
		sum = 0;

		while (N > 0) {
			a = N % 10;
			N /= 10;
			sum += pow(a, 2);
		}
		N = sum;

		if (s.find(N) != s.end()) return false;  // 说明进入无限循环
		else s.insert(N);
	}
	return true;
}	


int main()
{
	int n = 1;
	cout << isHappy(n) << endl;

	return 0;
}