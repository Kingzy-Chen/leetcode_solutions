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


ListNode *getIntersectionNode_v1(ListNode *headA, ListNode *headB) 
{
	ListNode* dummyA = new ListNode(-1, headA);
	ListNode* dummyB = new ListNode(-1, headB);
	ListNode* pA = dummyA;
	ListNode* pB = dummyB;

	// 计算链表 A 和 B 的长度
	int lenA = 0;
	int lenB = 0;
	while (pA->next != nullptr) {pA = pA->next; lenA += 1;}
	while (pB->next != nullptr) {pB = pB->next; lenB += 1;}
	if (lenA == 0 || lenB == 0) return nullptr;


	// 同时移动指针 pA 和 pB, 移动到链表末尾则跳转到另一个链表
	pA = dummyA;
	pB = dummyB;

	for (int i = 0; i < lenA + lenB + 1; i++) {
		if (pA == pB) return pA;

		if (pA->next == nullptr) pA = headB;  // 若 pA 到达末尾, 则跳转至 B 链
		else pA = pA->next;
		if (pB->next == nullptr) pB = headA;  // 若 pB 到达末尾, 则跳转至 A 链
		else pB = pB->next;
	}
	return nullptr;
}


ListNode *getIntersectionNode_v2(ListNode *headA, ListNode *headB) 
{
	ListNode* dummyA = new ListNode(-1, headA);
	ListNode* dummyB = new ListNode(-1, headB);
	ListNode* pA = dummyA;
	ListNode* pB = dummyB;

	// 计算链表 A 和 B 的长度
	int lenA = 0;
	int lenB = 0;
	while (pA->next != nullptr) {pA = pA->next; lenA += 1;}
	while (pB->next != nullptr) {pB = pB->next; lenB += 1;}
	if (lenA == 0 || lenB == 0) return nullptr;

	// 令 pA 成为最长链表的虚头节点
	pA = dummyA;
	pB = dummyB;

	if (lenB > lenA) {
		swap(lenA, lenB);
		swap(pA, pB);
	}

	// 计算长度差并且先移动 pA
	int gap = lenA - lenB;
	while (gap--) {
		pA = pA->next;
	}

	// 同时移动指针 pA 和 pB, 直至两者相遇
	while (pA->next != nullptr && pB->next != nullptr) {
		pA = pA->next;
		pB = pB->next;
		if (pA == pB) return pA;
	}
	return nullptr;
}


int main()
{
	vector<int> numsA = {0, 9, 1, 2, 4};
	vector<int> numsB = {3};
	ListNode* headA = initList(numsA);
	ListNode* headB = initList(numsB);

	headB->next = headA->next->next->next;
	printList(headA);
	printList(headB);
	cout << endl;

	ListNode* p1 = getIntersectionNode_v1(headA, headB);
	cout << p1->val << endl;
	ListNode* p2 = getIntersectionNode_v2(headA, headB);
	cout << p2->val << endl;

	return 0;
}