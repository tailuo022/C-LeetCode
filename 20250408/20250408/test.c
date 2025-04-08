

//3396

/*
给你一个整数数组 nums，你需要确保数组中的元素 互不相同 。为此，你可以执行以下操作任意次：
从数组的开头移除 3 个元素。如果数组中元素少于 3 个，则移除所有剩余元素。
注意：空数组也视作为数组元素互不相同。返回使数组元素互不相同所需的 最少操作次数 。
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



// 声明 isUnique 函数
bool isUnique(int* arr, int size);

int minimumOperations(int* nums, int numsSize) {
	for (int k = 0; ; k++) {
		int start = 3 * k; // 每次移除前k组的3个元素
		int remainingSize = numsSize - start;

		// 剩余数组为空或元素互不相同
		if (remainingSize <= 0 || isUnique(nums + start, remainingSize)) {
			return k;
		}
	}
}

// 检查数组中是否有重复元素
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