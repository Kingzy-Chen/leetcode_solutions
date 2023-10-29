#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


string process(string s) 
{
	int slow = 0;
	int fast = 0;

	for (fast = 0; fast < s.size(); fast++) 
	{
		// 用快指针替换非 # 值
		if (s[fast] != '#') {
			s[slow++] = s[fast];
		}
		// 遇到 #, 慢指针回退
		else {
			if (slow >= 1) slow--;
		}
	}
	// cout << s << endl;
	return s.substr(0, slow);
}


bool backspaceCompare(string s, string t) 
{
	string s_sub = process(s);
	string t_sub = process(t);
	cout << s_sub << " " << t_sub << endl;
	return s_sub == t_sub;
}


int main()
{
	string s1 = "ab#c";
	string t1 = "ad#c";
	cout << backspaceCompare(s1, t1) << endl;

	string s2 = "ab##";
	string t2 = "c#d#";
	cout << backspaceCompare(s2, t2) << endl;

	string s3 = "#a#b";
	string t3 = "b#b";
	cout << backspaceCompare(s3, t3) << endl;

	return 0;
}