
#include "stdio.h"
#include "math.h"
#include "stdbool.h"
#include "stdlib.h"

bool Is_Prime(int n) {
	int i = 2;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) break;
	}
	if (i > sqrt(n)) {
		return true;
	}
	else {
		return false;
	}
}

int** findPrimePairs(int n, int* returnSize, int** returnColumnSizes) {
	int** result = (int**)malloc(sizeof(int*) * n);
	//*returnColumnSizes = (int*)malloc(sizeof(int) * n * 2);
	*returnSize = 0;
	for (int i = 2; i <= n / 2; i++) {
		bool is1 = Is_Prime(i);
		bool is2 = Is_Prime(n - i);
		if (is1 && is2) {
			result[*returnSize] = (int*)malloc(sizeof(int) * 2);
			result[*returnSize][0] = i;
			result[*returnSize][1] = n - i;
			returnColumnSizes[*returnSize] = (int*)malloc(sizeof(int) * 2);
			(*returnColumnSizes)[(*returnSize) * 2] = i;
			(*returnColumnSizes)[(*returnSize) * 2 + 1] = n - i;
			(*returnSize)++;
		}
	}
	return result;
}