#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


string reverseWords(string s)
{
	int n = s.size();
	int slow = 0;
	int fast = 0;
	vector<string> v;

	while (slow < n && fast < n)
	{
		while (slow < n && s[slow] == ' ') slow++;  // 跳过单词前的空格
		fast = slow;
		while (fast < n && s[fast] != ' ') fast++;  // 找到单词后一位的空格

		// string.substr(i, n) 从索引 i 开始, 提取 n 个字符
		if (slow < n) v.push_back(s.substr(slow, fast - slow));
		slow = fast;
	}
	reverse(v.begin(), v.end());

	string ans = "";
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
		if (i < v.size() - 1) ans += " ";
	}
	return ans;
}


int main()
{
	string s = "  hello world ";
	cout << reverseWords(s) << endl;

	return 0;
}