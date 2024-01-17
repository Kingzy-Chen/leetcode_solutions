#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool lemonadeChange(vector<int>& bills) 
{
	int five_cnt = 0;
	int ten_cnt = 0;
	int twenty_cnt = 0;

	for (auto i: bills) {
		if (i == 5) {
			five_cnt += 1;
		}
		if (i == 10) {
			if (five_cnt <= 0) return false;
			ten_cnt += 1;
			five_cnt -= 1;
		}
		if (i == 20) {
			// 优先消耗 10 美元钞票
			if (five_cnt > 0 && ten_cnt > 0) {
				five_cnt -= 1;
				ten_cnt -= 1;
				twenty_cnt += 1;
			}
			else if (five_cnt >= 3) {
				five_cnt -= 3;
				twenty_cnt += 1;
			}
			else return false;
		}
	}
	return true;
}


int main()
{
	vector<int> bills1 = {5, 5, 5, 10, 20};
	cout << lemonadeChange(bills1) << endl;

	vector<int> bills2 = {5, 5, 10, 10, 20};
	cout << lemonadeChange(bills2) << endl;

	return 0;
}