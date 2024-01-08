#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


string reverseStr(string s, int k) 
{
	int n = s.size();

	for (int i = 0; i < n; i += (2 * k)) {
		if (i + k <= n) {
			reverse(s.begin() + i, s.begin() + i + k);
		}
		else {
			reverse(s.begin() + i, s.end());
		}
	}
	return s;
}


int main()
{
	string s1 = "abcdefg";
	int k1 = 2;
	cout << reverseStr(s1, k1) << endl;

	string s2 = "abcdefgh";
	int k2 = 3;
	cout << reverseStr(s2, k2) << endl;

	return 0;
}