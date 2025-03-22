
#include <stdlib.h>

//2643.
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = 0; res[1] = 0;
	for (int i = 0; i < matSize; i++) {
		int sum = 0;
		for (int j = 0; j < *matColSize; j++)
			sum += mat[i][j];
		if (sum > res[1]) {
			res[1] = sum;
			res[0] = i;
		}
	}
	*returnSize = 2;
	return res;
}

//1446.
int maxPower(char* s) {
	int sum = 0;
	char c = '0';
	int i = 0;
	int num = 1;
	int len = strlen(s);
	while (i < len) {
		if (s[i] != c) {
			c = s[i];
			if (num > sum) sum = num;
			num = 1;
		}
		else {
			num++;
		}
		i++;
	}
	if (num > sum) sum = num;
	return sum;
}

//1528.
char* restoreString(char* s, int* indices, int indicesSize) {
	char* ret = (char*)malloc(sizeof(char) * (indicesSize + 1));
	for (int i = 0; i < indicesSize; i++) {
		ret[indices[i]] = s[i];
	}
	ret[indicesSize] = '\0';
	return ret;
}
