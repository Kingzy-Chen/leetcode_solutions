#include <iostream>
#include <vector>
using namespace std;


// 单链表
struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

// 初始化链表
ListNode* initList(vector<int>& nums)
{
	ListNode* dummy = new ListNode(-1, nullptr);
	ListNode* p = dummy;

	for (auto i: nums) {
		ListNode* nxt = new ListNode(i, nullptr);
		p->next = nxt;
		p = p->next;
	}
	return dummy->next;
}

// 打印链表
void printList(ListNode* head)
{
	ListNode* dummy = new ListNode(-1, head);
	ListNode* p = dummy;

	while (p->next != nullptr) {
		p = p->next;
		cout << p->val << " ";
	}
	cout << endl;
}


ListNode* removeElements(ListNode* head, int val)
{
	if (!head) return nullptr;

	// 虚拟头节点
	ListNode* dummy = new ListNode(-1, head);
	ListNode* p = dummy;

	while (p->next != nullptr) 
	{
		if (p->next->val == val) {
			ListNode* tmp = p->next;
			p->next = p->next->next;
			delete tmp;  // 手动释放空间
		}
		else p = p->next;
	}
	return dummy->next;
}


int main()
{
	vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
	ListNode* head = initList(nums);

	int val = 6;
	head = removeElements(head, val);
	printList(head);

	return 0;
}