#include <iostream>
#include <vector>
using namespace std;


class MyLinkedList {
public:
	// 定义链表
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode* next): val(x), next(next) {}
    };

    // 链表长度和虚拟头节点
    int length;
    ListNode* dummy;

    // 初始化
    MyLinkedList() {
        length = 0;
        dummy = new ListNode(-1, nullptr);
    }
    
    // 获取下标为 index 的元素
    int get(int index) {
        if (index < 0 || index >= length) return -1;

        ListNode* p = dummy;
        for (int i = 0; i < index; i++) p = p->next;
        return p->next->val;
    }
    
    // 在链表头添加节点
    void addAtHead(int val) {
        ListNode* node = new ListNode(val, dummy->next);
        dummy->next = node;
        length++;
    }
    
    // 在链表末端添加节点
    void addAtTail(int val) {
        ListNode* p = dummy;
        while (p->next != nullptr) p = p->next;

        ListNode* node = new ListNode(val, p->next);
        p->next = node;
        length++;
    }
    
    // 在下标为 index 的元素前添加节点, 若 index 等于链表长度, 则添加至链表末端
    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;

        ListNode* p = dummy;
        for (int i = 0; i < index; i++) p = p->next;

        ListNode* node = new ListNode(val, p->next);
        p->next = node;
        length++;
    }
    
    // 删除下标为 index 的节点
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;

        ListNode* p = dummy;
        for (int i = 0; i < index; i++) p = p->next;

        ListNode* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        length--;
    }
};


int main()
{
	MyLinkedList myLinkedList;
	myLinkedList.addAtHead(1);
	myLinkedList.addAtTail(3);
	myLinkedList.addAtIndex(1, 2);          // 链表变为 1->2->3
	cout << myLinkedList.get(1) << endl;    // 返回 2
	myLinkedList.deleteAtIndex(1);          // 链表变为 1->3
	cout << myLinkedList.get(1) << endl;    // 返回 3

	return 0;
}