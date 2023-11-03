#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;


int evalRPN(vector<string>& tokens) 
{
	stack<int> stk;

	for (auto s: tokens) {
		if (s == "+" || s == "-" || s == "*" || s == "/") {
			int num1 = stk.top();  stk.pop();
			int num2 = stk.top();  stk.pop();

			if (s == "/") stk.push(num2 / num1);
			else if (s == "+") stk.push(num2 + num1);
			else if (s == "-") stk.push(num2 - num1);
			else if (s == "*") stk.push(num2 * num1);
		}
		else {
			stk.push(stoi(s));  // string to int
		}
	}

	int ans = stk.top();
	return ans;
}


int main()
{
	vector<string> tokens = {"2", "1", "+", "3", "*"};
	int ans = evalRPN(tokens);
	cout << ans << endl;

	return 0;
}