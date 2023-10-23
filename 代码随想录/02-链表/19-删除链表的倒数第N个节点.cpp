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


ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* dummy = new ListNode(-1, head);
	ListNode* p = dummy;
	int len = 0;
	while (p->next != nullptr) {len += 1; p = p->next;}

	p = dummy;
	for (int i = 0; i < len - n; i++) {p = p->next;}

	ListNode* tmp = p->next;
	p->next = p->next->next;
	delete tmp;

	return dummy->next;
}


int main()
{
	vector<int> nums = {1, 2, 3, 4, 5};
	ListNode* head = initList(nums);

	int n = 2;
	head = removeNthFromEnd(head, n);
	printList(head);
	
	return 0;
}