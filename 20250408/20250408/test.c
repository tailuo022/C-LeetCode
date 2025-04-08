

//3396

/*
����һ���������� nums������Ҫȷ�������е�Ԫ�� ������ͬ ��Ϊ�ˣ������ִ�����²�������Σ�
������Ŀ�ͷ�Ƴ� 3 ��Ԫ�ء����������Ԫ������ 3 �������Ƴ�����ʣ��Ԫ�ء�
ע�⣺������Ҳ����Ϊ����Ԫ�ػ�����ͬ������ʹ����Ԫ�ػ�����ͬ����� ���ٲ������� ��
*/

int SUB(int i, int j, int** num) {
	int res[3] = { 0 };
	for (int k = 0; k < 3; k++) {
		res[k] = num[j][k] - num[i][k];
	}
	if (res[0] == 0 || res[1] == 0 || res[2] == 0) {
		return j;
	}
	else {
		if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) {
			return j;
		}
		return 0;
	}
}

int minimumOperations(int* nums, int numsSize) {
	int** num = (int**)malloc(sizeof(int**) * (numsSize / 3 + 1));
	for (int i = 0; i < (numsSize / 3 + 1); i++) {
		num[i] = (int*)malloc(sizeof(int) * 3);
	}
	for (int i = 0, k = 0; i < numsSize; i++) {
		for (int j = 0; j < 3; j++) {
			num[k][j] = nums[i];
		}
		k++;
	}
	int res = 0;
	for (int i = 0; i < (numsSize / 3 + 1); i++) {
		for (int j = i; j < (numsSize / 3 + 1); j++) {
			int ret = SUB(i, j, num);
			if (ret > res) {
				res = ret;
			}
		}
	}
	if (numsSize / 3 * 3 == numsSize) {
		return res;
	}
	else {
		return res - 1;
	}
}



// ���� isUnique ����
bool isUnique(int* arr, int size);

int minimumOperations(int* nums, int numsSize) {
	for (int k = 0; ; k++) {
		int start = 3 * k; // ÿ���Ƴ�ǰk���3��Ԫ��
		int remainingSize = numsSize - start;

		// ʣ������Ϊ�ջ�Ԫ�ػ�����ͬ
		if (remainingSize <= 0 || isUnique(nums + start, remainingSize)) {
			return k;
		}
	}
}

// ����������Ƿ����ظ�Ԫ��
bool isUnique(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				return false;
			}
		}
	}
	return true;
}

/*

*/