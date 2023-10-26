#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generateMatrix(int n) 
{
	vector<vector<int>> M(n, vector<int>(n, 0));
	int start_i = 0;
	int start_j = 0;
	int end_i = n - 1;
	int end_j = n - 1;

	int k = 1;
	int i = 0;
	int j = 0;
	int cycles = n/2;  // 绕一周的次数

	while (cycles--) 
	{
		for (j = start_j; j < end_j; j++) M[i][j] = k++;
		for (i = start_i; i < end_i; i++) M[i][j] = k++;
		for (j = end_j; j > start_j; j--) M[i][j] = k++;
		for (i = end_i; i > start_i; i--) M[i][j] = k++;

		// 绕完一周, 修改 start 和 end
		start_i++;
		start_j++;
		end_i--;
		end_j--;
		i = start_i;
		j = start_j;
	}

	// 若 n 为奇数, 则将矩阵最中间元素补充
	if (n % 2 != 0) {
		M[n/2][n/2] = k;
	}
	return M;
}


int main()
{
	int n = 3;
	vector<vector<int>> ans = generateMatrix(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}