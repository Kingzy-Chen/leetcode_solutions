#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


string reverseLeftWords(string s, int k) 
{
	// abcdefg -> gfedcba -> cdefg ba -> cdefg ab -> cdefgab
	int n = s.size();
	reverse(s.begin(), s.end());
	reverse(s.begin(), s.begin() + n - k);
	reverse(s.begin() + n - k, s.end());
	return s;
}	


int main()
{
	string s1 = "abcdefg";
	int k1 = 2;
	cout << reverseLeftWords(s1, k1) << endl;

	string s2 = "lrloseumgh";
	int k2 = 6;
	cout << reverseLeftWords(s2, k2) << endl;

	return 0;
}