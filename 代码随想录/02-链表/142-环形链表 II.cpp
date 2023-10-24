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


ListNode* detectCycle(ListNode *head) 
{
	if (!head) return nullptr;

	// 快慢指针, 快指针每次移动两步, 慢指针每次移动一步
	ListNode* fast = head;
	ListNode* slow = head;

	do {
		if (slow->next == nullptr) return nullptr;
		if (fast->next == nullptr || fast->next->next == nullptr) return nullptr;
		slow = slow->next;
		fast = fast->next->next;

	} while(slow != fast);

	// 当两者相遇时, 重新从 head 和 fast 出发两个指针, 两指针相遇点即为环形入口
	ListNode* p1 = head;
	ListNode* p2 = fast;
	while (p1 != p2) {p1 = p1->next; p2 = p2->next;}
	return p1;
}


int main()
{
	vector<int> nums = {3, 2, 0, -4};
	ListNode* head = initList(nums);

	head->next->next->next->next = head->next;
	ListNode* p = detectCycle(head);
	cout << p->val << endl;

	return 0;
}