#include <iostream>
#include <cmath>
using namespace std;


bool isPerfectSquare(int num)
{
	int left = 0;
	int right = num;

	while (left <= right) 
	{
		int mid = (left + right) / 2;

		if (mid > (double)num / mid) {
			right = mid - 1;
		}
		else if (mid < (double)num / mid) {
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