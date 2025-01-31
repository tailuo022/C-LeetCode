#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//  541.反转字符串 2
char* reverseStr(char* s, int k) {
	int n = strlen(s);
	for (int i = 0; i < n; i += 2 * k) {
		int left = i;
		int right = i + k < n ? i + k - 1 : n - 1;
		while (left < right) {
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			left++;
			right--;
		}
	}
	return s;
}

// 1. 两数之和
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* arr = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				arr[0] = i;
				arr[1] = j;
				return arr;
			}
		}
	}
}

// 9. 回文数
bool isPalindrome(int x) {
	if (x < 0) return false;
	int arr[100] = { 0 };
	int i = 0;
	while (x) {
		arr[i++] = x % 10;
		x /= 10;
	}
	for (int j = 0; j < i / 2; j++) {
		if (arr[j] != arr[i - j - 1])
			return false;
	}
	return true;
}
//第二个想法是将数字本身反转，然后将反转后的数字与原始数字进行比较，
//如果它们是相同的，那么这个数字就是回文。
//按照第二个想法，为了避免数字反转可能导致的溢出问题，
// 为什么不考虑只反转 int 数字的一半？
// 毕竟，如果该数字是回文，其后半部分反转后应该与原始数字的前半部分相同。

// 13. 罗马数字转整数
int romanToInt(char* s) {
	int n = strlen(s);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
		case 'I': {
			if (s[i + 1] == '\0') {
				sum += 1;
			}
			else if (s[i + 1] == 'V') {
				sum += 4;
				i++;
			}
			else if (s[i + 1] == 'X') {
				sum += 9;
				i++;
			}
			else sum += 1;
			break;
		}
		case 'V':
			sum += 5;
			break;
		case 'X': {
			if (s[i + 1] == '\0') {
				sum += 10;
			}
			else if (s[i + 1] == 'L') {
				sum += 40;
				i++;
			}
			else if (s[i + 1] == 'C') {
				sum += 90;
				i++;
			}
			else sum += 10;
			break;
		}
		case 'L':
			sum += 50;
			break;
		case 'C': {
			if (s[i + 1] == '\0') {
				sum += 100;
			}
			else if (s[i + 1] == 'D') {
				sum += 400;
				i++;
			}
			else if (s[i + 1] == 'M') {
				sum += 900;
				i++;
			}
			else sum += 100;
			break;
		}
		case 'D':
			sum += 500;
			break;
		case 'M':
			sum += 1000;
			break;
		}
	}
	return sum;
}
int romanToInt(char* s) {
	int sum = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I') {
			if (i < n - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
				sum += (s[i + 1] == 'V') ? 4 : 9;
				i++;
			}
			else {
				sum += 1;
			}
		}
		else if (s[i] == 'V') {
			sum += 5;
		}
		else if (s[i] == 'X') {
			if (i < n - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
				sum += (s[i + 1] == 'L') ? 40 : 90;
				i++;
			}
			else {
				sum += 10;
			}
		}
		else if (s[i] == 'L') {
			sum += 50;
		}
		else if (s[i] == 'C') {
			if (i < n - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
				sum += (s[i + 1] == 'D') ? 400 : 900;
				i++;
			}
			else {
				sum += 100;
			}
		}
		else if (s[i] == 'D') {
			sum += 500;
		}
		else if (s[i] == 'M') {
			sum += 1000;
		}
	}
	return sum;
}

