#define  _CRT_SECURE_NO_WARNINGS\

#include <stdio.h>

// 143. 重排链表

struct ListNode {
    int val;
    struct ListNode* next;
};

// 思路1：暴力解法 -> 超时

//void reorderList(struct ListNode* head) {
//    struct ListNode* p, * tail;
//    p =  head;
//    while (p->next) {
//        tail = p;
//        while (tail->next) {
//            tail = tail->next;
//        } //找到当前尾节点
//        if (tail == p->next) {
//            break;
//        }
//        tail->next = p->next;
//        p->next = tail;
//        p = tail->next;
//    }
//    struct ListNode* i = head;
//    while (i->next != tail) {
//        i = i->next;
//    }
//    i->next = NULL;
//} 



// 思路2：中间节点 -> 反转后半部分 -> 依次链接

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = head; fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }
    struct ListNode* mid = middleNode(head);
    struct ListNode* front = head;
    struct ListNode* back = mid->next;
    back = reverseList(back);
    mid->next = NULL;

    struct ListNode* Head = (struct ListNode*)malloc(sizeof(struct ListNode));
    Head->next = NULL;
    struct ListNode* p = Head;
    while (front && back) {
        struct ListNode* tmpfront = front->next;
        struct ListNode* tmpback = back->next;
        p->next = front;
        front->next = back;
        p = p->next->next;
        front = tmpfront;
        back = tmpback;
    }
    if (front) {
        p->next = front;
    }
    head = Head->next;
}