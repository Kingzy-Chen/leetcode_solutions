#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int candy(vector<int>& ratings) 
{
	// 每人至少一个糖果
	int n = ratings.size();
	vector<int> A(n, 1);

	// 从左往右检查每个孩子的左手边
	for (int i = 0; i < n - 1; i++) {
		if (ratings[i] < ratings[i + 1] && A[i] >= A[i + 1]) {
			A[i + 1] = A[i] + 1;
		}
	}

	// 从右往左检查每个孩子的右手边
	for (int i = n - 1; i > 0; i--) {
		if (ratings[i] < ratings[i - 1] && A[i] >= A[i - 1]) {
			A[i - 1] = A[i] + 1;
		}
	}

	int sum = 0;
	for (auto i: A) sum += i;
	return sum;
}


int main()
{
	vector<int> ratings1 = {1, 0, 2};
	cout << candy(ratings1) << endl;

	vector<int> ratings2 = {1, 2, 2};
	cout << candy(ratings2) << endl;

	return 0;
}