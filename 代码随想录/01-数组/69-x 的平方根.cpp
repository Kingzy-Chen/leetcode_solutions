#include <iostream>
#include <cmath>
using namespace std;


int mySqrt(int x)
{
	int left = 0;
	int right = x;
	int ans = -1

	// x 平方根的整数部分满足 k^2 <= x 的最大 k 值
	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		if ((long long)mid * mid <= x) {  // mid * mid 用 int 会导致溢出
			ans = mid;  
			left = mid + 1;  // 更新 left 变量, 从而向右搜索 k 值
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}


int main()
{
	int x = 8;
	int ans = mySqrt(x);
	cout << ans << endl;

	return 0;
}