#define  _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>

// 2. 两数相加

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p1 = l1, * p2 = l2;
	long long a1 = 0, a2 = 0;
	long long count1 = 1, count2 = 1;
	while (p1) {
		a1 = a1 + count1 * p1->val;
		count1 *= 10;
		p1 = p1->next;
	}
	while (p2) {
		a2 = a2 + count2 * p2->val;
		count2 *= 10;
		p2 = p2->next;
	}
	long long sum = a1 + a2;
	if (sum == 0) {
		struct ListNode* psum = (struct ListNode*)malloc(sizeof(struct ListNode));
		psum->val = sum;
		psum->next = NULL;
		return psum;
	}
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->next = NULL;
	struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre = p;
	while (sum) {
		struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode));
		next->val = sum % 10;
		sum /= 10;
		next->next = NULL;
		pre->next = next;
		pre = next;
	}
	return p->next;
} //转换为数字后相加 -> 数字溢出

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int array = 0;
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p = head;
	while (l1 || l2) {
		int x = l1 ? l1->val : 0;
		int y = l2 ? l2->val : 0;
		int sum = array + x + y;
		array = sum / 10;
		struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode));
		next->val = sum % 10;
		next->next = NULL;
		p->next = next;
		p = next;
		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}
	}
	if (array > 0) {
		struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode));
		next->val = array;
		next->next = NULL;
		p->next = next;
		p = next;
	}
	return head->next;
} //逐位相加