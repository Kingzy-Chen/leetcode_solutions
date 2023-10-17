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
	int num = 14;
	bool ans = isPerfectSquare(num);
	cout << ans << endl;

	return 0;
}