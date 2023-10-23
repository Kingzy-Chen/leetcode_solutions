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


ListNode* swapPairs(ListNode* head) 
{
	if (!head) return nullptr;

	ListNode* dummy = new ListNode(-1, head);
	ListNode* p1 = dummy;
	ListNode* p2 = head;
	ListNode* p3 = head->next;

	while (p2 != nullptr && p3 != nullptr) 
	{
		p1->next = p2->next;
		p2->next = p3->next;
		p3->next = p2;

		p1 = p1->next->next;
		p2 = p1->next;
		if (p2) p3 = p2->next;
		else p3 = nullptr;
	}
	return dummy->next;
}


int main()
{
	vector<int> nums = {1, 2, 3, 4};
	ListNode* head = initList(nums);

	head = swapPairs(head);
	printList(head);
	
	return 0;
}