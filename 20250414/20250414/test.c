

//1534.

/*
给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。

如果三元组 (arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。

0 <= i < j < k < arr.length
|	arr[i] - arr[j]| <= a
|	arr[j] - arr[k]| <= b
|	arr[i] - arr[k]| <= c
其中 |x| 表示 x 的绝对值。

返回 好三元组的数量 。
*/

int my_abs(int a, int b) {
	if (a - b >= 0) {
		return a - b;
	}
	return b - a;
}

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
	int sum = 0;
	for (int i = 0; i < arrSize; i++) {
		for (int j = i + 1; j < arrSize; j++) {
			for (int k = j + 1; k < arrSize; k++) {
				int res_a = my_abs(arr[i], arr[j]);
				int res_b = my_abs(arr[j], arr[k]);
				int res_c = my_abs(arr[i], arr[k]);
				if (res_a <= a && res_b <= b && res_c <= c) {
					sum++;
				}
			}
		}
	}
	return sum;
}
