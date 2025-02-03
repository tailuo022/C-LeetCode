#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// 94. 二叉树的中序遍历
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
void inordor(struct TreeNode* root, int* res, int* resSize) {
	if (root == NULL) {
		return;
	}
	inordor(root->left, res, resSize);
	res[(*resSize)++] = root->val;
	inordor(root->right, res, resSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* res = (int*)malloc(sizeof(int) * 101);
	*returnSize = 0;
	inordor(root, res, returnSize);
	return res;
}

// 100. 相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	else if (p == NULL || q == NULL) {
		return false;
	}
	else if (p->val != q->val) {
		return false;
	}
	else {
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}

// 101. 对称二叉树
bool check(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
	return check(root->left, root->right);
}

// 104. 二叉树的最大深度
int maxDepth(struct TreeNode* root) {
	if (root == NULL) return 0;
	return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}