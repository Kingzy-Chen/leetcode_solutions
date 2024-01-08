#include <iostream>
#include <queue>
using namespace std;


class MyStack {
public:
	queue<int> que1;
	queue<int> que2;

	MyStack() {

	}

	// 将元素 x 压入栈顶
	void push(int x) {
		que1.push(x);
	}

	// 移除并返回栈顶元素
	int pop() {
		// 将 que1 导入 que2 但剩下最后一个元素
		while (que1.size() > 1) {
			que2.push(que1.front());
			que1.pop();
		}
		// 返回最后一个元素
		int ans = que1.front();
		que1.pop();

		// 将 que2 赋值给 que1
		que1 = que2;
		
		// 清空 que2
		while (!que2.empty()) {
			que2.pop();
		}
		return ans;
	}

	// 返回栈顶元素
	int top() {
		return que1.back();
	}

	// 判断栈是否为空
	bool empty() {
		return que1.empty();
	}
};


int main()
{
	MyStack myStack;
	myStack.push(1);
	myStack.push(2);
	cout << myStack.top() << endl;  // 返回 2
	cout << myStack.pop() << endl;  // 返回 2
	cout << myStack.empty() << endl;  // 返回 False

	return 0;
}