#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


void reverseString(vector<char>& s) 
{
	int n = s.size();
	int left = 0;
	int right = n - 1;

	while (left <= right) 
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
}


int main()
{
	vector<char> s = {'h', 'e', 'l', 'l', 'o'};
	reverseString(s);

	for (auto c: s) cout << c << " ";
	cout << endl;

	return 0;
}