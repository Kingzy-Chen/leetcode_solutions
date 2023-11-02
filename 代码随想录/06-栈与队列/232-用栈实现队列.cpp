#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:
	stack<int> stk1;
	stack<int> stk2;

	MyQueue() {

	}

	// 将元素 x 推到队列的末尾
	void push(int x) {
		stk1.push(x);
	}

	// 从队列的开头移除并返回元素
	int pop() {
		// 当 stk2 为空时, 从 stk1 导入数据
		if (stk2.empty()) {
			while (!stk1.empty()) {
				stk2.push(stk1.top());
				stk1.pop();
			}
		}
		// 返回 stk2 栈顶元素
		int ans = stk2.top();
		stk2.pop();
		return ans;
	}

	// 返回队列开头的元素
	int peek() {
		int ans = this->pop();  // 逻辑相同, 直接调用 pop() 函数
		stk2.push(ans);  // 但要将 ans 重新压入 stk2
		return ans;
	}

	// 判读队列是否为空
	bool empty() {
		return stk1.empty() && stk2.empty();
	}
};


int main()
{
	MyQueue myQueue;
	myQueue.push(1);
	myQueue.push(2);
	cout << myQueue.peek() << endl;  // 返回 1
	cout << myQueue.pop() << endl;   // 返回 1
	cout << myQueue.empty() << endl;  // 返回 False

	return 0;
}