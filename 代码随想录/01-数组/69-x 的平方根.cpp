#include <iostream>
#include <cmath>
using namespace std;


int mySqrt(int x)
{
	int left = 0;
	int right = x;

	while (left <= right) 
	{
		int mid = (left + right) / 2;

		if (mid < int(sqrt(x))) {
			left = mid + 1;
		}
		else if (mid > int(sqrt(x))) {
			right = mid - 1;
		}
		else return mid;
	}
	return -1;
}


int main()
{
	int x = 8;
	int ans = mySqrt(x);
	cout << ans << endl;

	return 0;
}