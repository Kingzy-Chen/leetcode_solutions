#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int monotoneIncreasingDigits(int n) 
{
	// 逐位数字存到数组
	vector<int> number;
	while (n) {number.push_back(n % 10); n /= 10;}

	// 从低位数字往高位数字比较  1554 -> 1549 -> 1499
	int len = number.size();
	int position = -1;

	for (int i = 0; i < len - 1; i++) {
		if (number[i] < number[i + 1]) {
			number[i + 1] -= 1;  // 高位数字减 1
			position = i;
		}
	}

	// 从最低位至 position 数字都替换为 9
	for (int i = 0; i <= position; i++) {
		number[i] = 9;
	}

	// 计算新数字
	int ans = 0;
	for (int i = 0; i < len; i++) {
		ans += (number[i] * pow(10, i));
	}
	return ans;
}


int main()
{
	int n1 = 10;
	cout << monotoneIncreasingDigits(n1) << endl;

	int n2 = 1234;
	cout << monotoneIncreasingDigits(n2) << endl;

	int n3 = 332;
	cout << monotoneIncreasingDigits(n3) << endl;

	return 0;
}