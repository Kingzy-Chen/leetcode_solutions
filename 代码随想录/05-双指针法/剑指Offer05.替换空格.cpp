#include <iostream>
#include <cstring>
using namespace std;


string replaceSpace(string s)
{
	int n = s.size();
	int cntSpace = 0;

	// 计算空格数量
	for (auto c: s) {
		if (c == ' ') cntSpace += 1;
	}

	// 用 resize 重新开辟空间
	s.resize(s.size() + 2 * cntSpace);

	// 指定 fast 指针在新字符串末尾, slow 指针在原字符串末尾, 同时向前回退
	int slow = n - 1;
	int fast = s.size() - 1;

	while (slow >= 0) {
		if (s[slow] != ' ') {
			s[fast--] = s[slow--];
		}
		else {
			s[fast--] = '0';
			s[fast--] = '2';
			s[fast--] = '%';
			slow--;
		}
	}
	return s;
}


int main()
{
	string s = "We are happy.";
	string ans = replaceSpace(s);
	cout << ans << endl;

	return 0;
}