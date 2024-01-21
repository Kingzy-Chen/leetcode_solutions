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


ListNode* removeNthFromEnd_v1(ListNode* head, int n) 
{
	ListNode* dummy = new ListNode(-1, head);
	ListNode* p = dummy;

	// 先计算链表长度
	int len = 0;
	while (p->next != nullptr) {len += 1; p = p->next;}

	// 再到指定位置删除节点
	p = dummy;
	for (int i = 0; i < len - n; i++) {p = p->next;}

	ListNode* tmp = p->next;
	p->next = p->next->next;
	delete tmp;

	return dummy->next;
}


ListNode* removeNthFromEnd_v2(ListNode* head, int n)
{
	ListNode* dummy = new ListNode(-1, head);
	ListNode* fast = dummy;
	ListNode* slow = dummy;

	// 先移动 fast 指针
	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}
	// 再同时移动 fast 和 slow 指针
	while (fast->next != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	// 删除节点
	ListNode* tmp = slow->next;
	slow->next = slow->next->next;
	delete tmp;

	return dummy->next;
}


int main()
{
	vector<int> nums1 = {1, 2, 3, 4, 5};
	ListNode* head1 = initList(nums1);

	int n1 = 2;
	head1 = removeNthFromEnd_v1(head1, n1);
	printList(head1);

	vector<int> nums2 = {1};
	ListNode* head2 = initList(nums2);

	int n2 = 1;
	head2 = removeNthFromEnd_v2(head2, n2);
	printList(head2);
	
	return 0;
}