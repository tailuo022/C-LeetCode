
//2829.

/*
������������ n �� k ��
����һ���� ��ͬ ��������ɵ����飬
������в������κ���͵��� k �Ĳ�ͬԪ�ضԣ������Ϊ k - avoiding ���顣
���س���Ϊ n �� k - avoiding ����Ŀ��ܵ���С�ܺ͡�
*/

int minimumSum(int n, int k) {
	int sum = 0;
	int count = 0;
	for (int i = 1; i <= k / 2 && count < n; i++) {
		sum += i;
		count++;
	}
	int start = k;
	while (count < n) {
		sum += start;
		start++;
		count++;
	}
	return sum;
}

/*
����˼·����������С���ܣ������Ϊ k ������£�
	�������Ϊ[1, k - 1]��[2, k -2]��... ��[k / 2 - 1, k / 2 + 1]��[k / 2,  k / 2]��
	����ȡ���(1��2��... ��k / 2 - 1��k / 2)Ϊ����Ԫ�أ�
	������û���������ٴ�k��k+1��... �����������顣
���룺i <= k / 2 && count < n��
	ǰ����ȡ��������С��k��ֵ������û��������
	֮��� count < n ���������ʣ�µ�λ�����ϡ������ǻ�û�е� k ��һ�㵫�������Ѿ����ˣ�ֱ�������

���ߣ�tailuo022
���ӣ�https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/solutions/3628571/onshi-jian-zhao-chu-shu-zu-quan-bu-nei-r-gdv2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/