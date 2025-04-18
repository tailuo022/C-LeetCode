

//2364.

/*
����һ���±�� 0 ��ʼ���������� nums ��
	��� i < j �� j - i != nums[j] - nums[i] ����ô���ǳ� (i, j) ��һ�� ������ ��
���㷵�� nums �� ������ ������Ŀ��
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
    good_pairs += (long long)count * (count - 1) / 2; // �������һ��

    free(diff);
    return total_pairs - good_pairs;
}