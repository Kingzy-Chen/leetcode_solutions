#include <iostream>
#include <cmath>
using namespace std;


bool isPerfectSquare(int num)
{
	int left = 0;
	int right = num;

	while (left <= right) 
	{
		int mid = (right - left) / 2 + left;

		if ((long long)mid * mid > num) {  // mid * mid 用 int 会导致溢出
			right = mid - 1;
		}
		else if ((long long) mid * mid < num) {
			left = mid + 1;
		}
		else return true;
	}
	return false;
}


int main()
{
	int num1 = 16;
	cout << isPerfectSquare(num1) << endl;

	int num2 = 14;
	cout << isPerfectSquare(num2) << endl;

	return 0;
}