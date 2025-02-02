#define  _CRT_SECURE_NO_WARNINGS

// 35. 搜索插入位置
int searchInsert(int* nums, int numsSize, int target) {
	int left = 0;
	int right = numsSize - 1;
	int mid = (left + right) / 2;
	while (left < right) {
		if (target < nums[mid]) {
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else if (target > nums[mid]) {
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else {
			return mid;
		}
	}
	if (nums[left] < target) {
		return left + 1;
	}
	else {
		return left;
	}
}

// 58. 最后一个单词长度
int lengthOfLastWord(char* s) {
	int p;
	for (p = 0; s[p] != '\0'; p++);
	int count = 0;
	for (int i = p - 1; i >= 0; i--) {
		if (s[i] == ' ' && count != 0) {
			break;
		}
		if (s[i] != ' ') {
			count++;
		}
	}
	return count;
}

// 66. 加一
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int i = 0;
	for (i = digitsSize -  1; i >= 0; i--) {
		digits[i] = digits[i] + 1;
		if (digits[i] != 10) {
			*returnSize = digitsSize;
			return digits;
		}
		if (digits[i] == 10) {
			digits[i] = 0;
		}
	}
	int* p = (int*)malloc(sizeof(int) * (digitsSize + 1));
	memset(p, 0, sizeof(int) * (digitsSize + 1));
	p[0] = 1;
	*returnSize = digitsSize + 1;
	return p;
}

// 67. 二进制求和
void reserve(char* p) {
	int len = strlen(p);
	for (int i = 0; i < len / 2; i++) {
		char tmp = p[i];
		p[i] = p[len - i - 1];
		p[len - i - 1] = tmp;
	}
}
char* addBinary(char* a, char* b) {
	reserve(a);
	reserve(b);
	int len_a = strlen(a);
	int len_b = strlen(b);
	int n = len_a > len_b ? len_a : len_b;
	int carry = 0, len = 0;
	char* ans = (char*)malloc(sizeof(char) * (n + 2));
	for (int i = 0; i < n; i++) {
		carry += i < len_a ? (a[i] == '1') : 0;
		carry += i < len_b ? (b[i] == '1') : 0;
		ans[len++] = carry % 2 + '0';
		carry /= 2;
	}
	if (carry) {
		ans[len++] = '1';
	}
	ans[len] = '\0';
	reserve(ans);
	return ans;
}

// 60. x 的平方根
int mySqrt(int x) {
	if (x == 0 || x == 1) {
		return x;
	}
	int left = 1;
	int right = x;
	int result = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if ((long long)mid * mid <= x) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

// 70. 爬楼梯
int climbStairs(int n) {
	int first = 1;
	int second = 2;
	if (n == 1 || n == 2) {
		return n;
	}
	for (int i = 3; i <= n; i++) {
		int third = first + second;
		first = second;
		second = third;
	}
	return second;
}

// 83. 删除排序链表中的重复元素
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head) {
		return NULL;
	}
	int data = head->val;
	struct ListNode* p;
	p = head;
	while (p->next) {
		if (p->next->val != data) {
			data = p->next->val;
			p = p->next;
		}
		else {
			struct ListNode* q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	return head;
}

// 88. 合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	while (m > 0 && n > 0) {
		if (nums1[m - 1] >= nums2[n - 1]) {
			nums1[m + n - 1] = nums1[m - 1];
			m--;
		}
		else {
			nums1[m + n - 1] = nums2[n - 1];
			n--;
		}
	}
	while (m > 0) {
		return;
	}
	while (n > 0) {
		nums1[n - 1] = nums2[n - 1];
		n--;
	}
}
