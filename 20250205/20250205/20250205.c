#define  _CRT_SECURE_NO_WARNINGS

// 169. ����Ԫ��
int majorityElement(int* nums, int numsSize) {
	int target[1][2] = { nums[0], 1};
	for (int i = 1; i < numsSize; i++) {
		if (target[0][1] == 0) {
			target[0][0] = nums[i];
		}
		if (nums[i] != target[0][0]) {
			target[0][1]--;
		}
		if (nums[i] == target[0][0]) {
			target[0][1]++;
		}
	}
	return target[0][0];
}

// 171. Excel �������
int titleToNumber(char* columnTitle) {
	int count = 0;
	while (columnTitle[count] != '\0') {
		count++;
	}
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum = sum * 26 + (columnTitle[i] - 'A' + 1);
	}
	return sum;
}
