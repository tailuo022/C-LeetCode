

//2176.

/*
给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k ，
	请你返回满足 0 <= i < j < n ，nums[i] == nums[j] 且 (i * j) 
	能被 k 整除的数对 (i, j) 的 数目 。
*/

int countPairs(int* nums, int numsSize, int k) {
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] == nums[j] && i * j % k == 0) {
				sum++;
			}
		}
	}
	return sum;
}