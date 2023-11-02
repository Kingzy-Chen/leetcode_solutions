#include <iostream>
#include <stack>
#include <cstring>
using namespace std;


bool isValid(string s) 
{
	stack<char> stk;

	for (auto c: s) {
		if (c == '(' || c == '{' || c == '[') {
			stk.push(c);
		}
		else {
			if (!stk.empty() && c == ')' && stk.top() == '(') {
				stk.pop();
			}
			else if (!stk.empty() && c == '}' && stk.top() == '{') {
				stk.pop();
			}
			else if (!stk.empty() && c == ']' && stk.top() == '[') {
				stk.pop();
			}
			else {
				stk.push(c);
			}
		}
	}
	return stk.empty();
}


int main()
{
	string s1 = "()[]{}";
	cout << isValid(s1) << endl;

	string s2 = "(]";
	cout << isValid(s2) << endl;

	return 0;
}