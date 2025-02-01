#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 14. �����ǰ׺
char* longestCommonPrefix(char** strs, int strsSize) {
	if (!strsSize) {
		return NULL;
	}
	for (int i = 0; i < strlen(strs[0]); i++) {
		for (int j = 1; j < strsSize; j++) {
			if (strs[0][i] != strs[j][i]) {
				strs[0][i] = '\0';
				return strs[0];
			}
		}
	}
	return strs[0];
}

// 20. ��Ч������
bool isValid(char* s) {
	char* p;
	p = (char*)malloc(sizeof(char) * 10000);
	if (!p) {
		return false;
	}
	int len = strlen(s);
	if (len % 2 != 0) {
		return false;
	}
	int top = -1;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			p[++top] = s[i];
		}
		if (s[i] == ')')
			if (top == -1 || p[top--] != '(') {
				free(p);
				return false;
			}
		if (s[i] == '}')
			if (top == -1 || p[top--] != '{') {
				free(p);
				return false;
			}
		if (s[i] == ']')
			if (top == -1 || p[top--] != '[') {
				free(p);
				return false;
			}
	}
	bool result = (top == -1);
	free(p);
	p = NULL;
	return result;
}

// 21. �ϲ�������������
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode L;
	struct ListNode* p, * q, * head;
	p = list1; q = list2;
	head = &L;
	while (p && q) {
		if (p->val <= q->val) {
			head->next = p;
			p = p->next;
		}
		else {
			head->next = q;
			q = q->next;
		}
		head = head->next;
	}
	if (p) {
		head->next = p;
	}
	if (q) {
		head->next = q;
	}
	return L.next;
}

// 26. ɾ�����������е��ظ���
int removeDuplicates(int* nums, int numsSize) {
	int mem = nums[0];
	int count = 0;
	for (int i = 1; i < numsSize; i++) {
		if (mem != nums[i]) {
			mem = nums[i];
			nums[++count] = mem;
		}
	}
	return count + 1;
}

// 27. �Ƴ�Ԫ��
int removeElement(int* nums, int numsSize, int val) {
	int count = 0;
	int j = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != val) {
			nums[j++] = nums[i];
			count++;
		}
	}
	return count;
}

// 28. �ҳ��ַ����е�һ��ƥ������±�
int strStr(char* haystack, char* needle) {
	int i, j;
	i = j = 0;
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
	while (i < len1 && j < len2) {
		if (haystack[i] == needle[j]) {
			i++; j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= len2) {
		return i - len2;
	}
	else return -1;
}