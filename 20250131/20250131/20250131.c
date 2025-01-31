#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//  541.��ת�ַ��� 2
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

// 1. ����֮��
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

// 9. ������
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
//�ڶ����뷨�ǽ����ֱ���ת��Ȼ�󽫷�ת���������ԭʼ���ֽ��бȽϣ�
//�����������ͬ�ģ���ô������־��ǻ��ġ�
//���յڶ����뷨��Ϊ�˱������ַ�ת���ܵ��µ�������⣬
// Ϊʲô������ֻ��ת int ���ֵ�һ�룿
// �Ͼ�������������ǻ��ģ����벿�ַ�ת��Ӧ����ԭʼ���ֵ�ǰ�벿����ͬ��

// 13. ��������ת����
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

