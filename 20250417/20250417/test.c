

//2176.

/*
����һ���±�� 0 ��ʼ����Ϊ n ���������� nums ��һ������ k ��
	���㷵������ 0 <= i < j < n ��nums[i] == nums[j] �� (i * j) 
	�ܱ� k ���������� (i, j) �� ��Ŀ ��
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