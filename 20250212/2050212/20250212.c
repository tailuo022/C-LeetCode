#define  _CRT_SECURE_NO_WARNINGS

#include <math.h>

// LCR .090 ¥Úº“ΩŸ…· II

int Rob(int* nums, int start, int end) {
	int first = nums[start];
	int second = fmax(nums[start], nums[start + 1]);
	for (int i = start + 2; i <= end; i++) {
		int tmp = second;
		second = fmax(first + nums[i], second);
		first = tmp;
	}
	return second;
}

int rob(int* nums, int numsSize) {
	if (numsSize == 1) {
		return nums[0];
	}
	else if (numsSize == 2) {
		return fmax(nums[0], nums[1]);
	}
	return fmax(Rob(nums, 0, numsSize - 2), Rob(nums, 1, numsSize - 1));
}