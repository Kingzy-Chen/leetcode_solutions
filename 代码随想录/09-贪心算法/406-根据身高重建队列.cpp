#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printResult(vector<vector<int>> result)
{
	for (auto v: result) {
		cout << "[" << v[0] << "," << v[1] << "] ";
	}
	cout << endl << endl;
}


// 自定义排序
bool cmp(vector<int>& A, vector<int>& B)
{
	if (A[0] != B[0]) return A[0] < B[0];  // 身高从低至高
	else return A[1] > B[1];  // 相同身高 ki 大的排前面
}


vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
{
	sort(people.begin(), people.end(), cmp);
	int n = people.size();

	// 从倒数第二个人开始, 根据其 ki 与靠后的人调换位置
	for (int i = n - 2; i >= 0; i--) {

		// [5, 2] [6, 1] [7, 1] [7, 0]
		// -> [5, 2] [6, 1] [7, 0] [7, 1]
		// -> [5, 2] [7, 0] [6, 1] [7, 1]
		// -> [7, 0] [6, 1] [5, 2] [7, 1]
		int move = people[i][1];
		auto p = people[i];

		for (int j = i; j < i + move; j++) {
			people[j] = people[j + 1];
		}
		people[i + move] = p;
	}
	return people;       
}


int main()
{
	vector<vector<int>> people1 = {
		vector<int>{7, 0},
		vector<int>{4, 4},
		vector<int>{7, 1},
		vector<int>{5, 0},
		vector<int>{6, 1},
		vector<int>{5, 2},
	};
	printResult(reconstructQueue(people1));

	vector<vector<int>> people2 = {
		vector<int>{6, 0},
		vector<int>{5, 0},
		vector<int>{4, 0},
		vector<int>{3, 2},
		vector<int>{2, 2},
		vector<int>{1, 4},
	};
	printResult(reconstructQueue(people2));

	return 0;
}