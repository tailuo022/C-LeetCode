

//2364.

/*
给你一个下标从 0 开始的整数数组 nums 。
	如果 i < j 且 j - i != nums[j] - nums[i] ，那么我们称 (i, j) 是一个 坏数对 。
请你返回 nums 中 坏数对 的总数目。
*/

long long countBadPairs(int* nums, int numsSize) {
	long long sum = 0;
	long long hasharr[100000] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		hasharr[i] = nums[i] - i;
	}
	for (int j = 0; j < numsSize; j++) {
		if (nums[j] - j != hasharr[j]) {
			sum++;
		}
	}
	return sum;
} 

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long countBadPairs(int* nums, int numsSize) {
    long long total_pairs = (long long)numsSize * (numsSize - 1) / 2;
    int* diff = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; ++i) {
        diff[i] = nums[i] - i;
    }

    qsort(diff, numsSize, sizeof(int), compare);

    long long good_pairs = 0;
    int current = diff[0];
    int count = 1;

    for (int i = 1; i < numsSize; ++i) {
        if (diff[i] == current) {
            count++;
        }
        else {
            good_pairs += (long long)count * (count - 1) / 2;
            current = diff[i];
            count = 1;
        }
    }
    good_pairs += (long long)count * (count - 1) / 2; // 处理最后一组

    free(diff);
    return total_pairs - good_pairs;
}