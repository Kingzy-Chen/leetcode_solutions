#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;


bool isHappy(int n) 
{
	unordered_set<int> s;  // 存储出现过的结果
	int number = 0;
	int sum = 0;

	while (n != 1) {
		sum = 0;

		while (n > 0) {
			number = n % 10;
			n /= 10;
			sum += pow(number, 2);
		}
		n = sum;

		if (s.find(n) != s.end()) return false;  // 说明进入无限循环
		else s.insert(n);
	}
	return true;
}	


int main()
{
	int n1 = 19;
	cout << isHappy(n1) << endl;

	int n2 = 2;
	cout << isHappy(n2) << endl;

	return 0;
}