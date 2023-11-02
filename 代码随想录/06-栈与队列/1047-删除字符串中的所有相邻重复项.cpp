#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;


string removeDuplicates(string s) 
{
	stack<char> stk;
	string ans = "";

	for (auto c: s) {
		if (!stk.empty() && stk.top() == c) {
			stk.pop();
		}
		else {
			stk.push(c);
		}
	}

	while (!stk.empty()) {
		char c = stk.top();
		ans += c;
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


int main()
{
	string s = "abbaca";
	cout << removeDuplicates(s) << endl;

	return 0;
}