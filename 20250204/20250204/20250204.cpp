#define  _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdbool.h>

 typedef struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

 struct ListNode {
	 int val;
	 struct ListNode* next;
 };

// 136. 只出现一次的数字
int singleNumber(int* nums, int numsSize) {
	int result = nums[0];
	for (int i = 1; i < numsSize; i++) {
		result ^= nums[i];
	}
	return result;
}

// 144. 二叉树的先序遍历
int* preOrderTraverse(int* arr, TreeNode* root, int* returnSize) {
	if (root == NULL) {
		return arr;
	}
	arr[(*returnSize)++] = root->val;
	preOrderTraverse(arr, root->left, returnSize);
	preOrderTraverse(arr, root->right, returnSize);
	return arr;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	int* arr = (int*)malloc(sizeof(int) * 100);
	*returnSize = 0;
	arr = preOrderTraverse(arr, root, returnSize);
	return arr;
}

// 145. 二叉树的后序遍历
int* postOrderTraverse(int* arr, struct TreeNode* root, int* returnSize) {
	if (root == NULL) {
		return arr;
	}
	postOrderTraverse(arr, root->left, returnSize);
	postOrderTraverse(arr, root->right, returnSize);
	arr[(*returnSize)++] = root->val;
	return arr;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	int* arr = (int*)malloc(sizeof(int) * 100);
	*returnSize = 0;
	arr = postOrderTraverse(arr, root, returnSize);
	return arr;
}

// 141. 环形链表
bool hasCycle(struct ListNode* head) {
	if (!head) {
		return false;
	}
	struct ListNode* fast, * slow;
	slow = head;
	fast = head;
	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

// 160. 相交链表
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	struct ListNode* p, * q;
	p = headA;
	q = headB;
	while (p != q) {
		p = p == NULL ? headB : p->next;
		q = q == NULL ? headA : p->next;
	}
	return p;
}