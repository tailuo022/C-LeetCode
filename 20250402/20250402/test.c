

//2873.

/*
����һ���±�� 0 ��ʼ���������� nums ��
������������� i < j < k ���±���Ԫ�� (i, j, k) �У��ҳ��������±���Ԫ������ֵ��
	�������������������Ԫ���ֵ���Ǹ������򷵻� 0 ��
�±���Ԫ�� (i, j, k) ��ֵ���� (nums[i] - nums[j]) * nums[k] ��
*/

long long max(long long a, long long b) {
	if (a > b)
		return a;
	return b;
}

long long maximumTripletValue(int* nums, int numsSize) {
	long long res = 0;
	for (int i = 0; i < numsSize; i++)
		for (int j = i + 1; j < numsSize; j++)
			for (int k = j + 1; k < numsSize; k++)
				res = max(((long long)nums[i] - nums[j]) * nums[k], res);
	return res;
}

/*
�������Ҫ�ü򵥵Ľⷨ(
	����ѭ��ö������������Ƚϱ������ֵ��
	���ܵ����⣺
		��Ҫ������һ�� int ǿ��ת��Ϊ long long ���ͣ�������������������������
			ȫ����Ϊ long long ���ͽ������㣬�Ƚ���������ǿ��ת��Ϊ long long ���͵Ļ���
			������������ int �ķ�Χ�Ļ���������ʽ�õ��������һ�̣��ͷ����˽ض�
			(�����治�µ�λ��ȥ����ȥ���ָ�λ)����ʱ�ڽ���ǿ������ת����
			���ǰ��Ѿ��ضϵĵĽ������������������Ǵ���Ľ����
	ʹ���Դ��ıȽϺ�����û��������⣬�����Ǽ���(��ѧ��)�����Ƕ��һ��֪ʶ�ĺ�(

���ߣ�tailuo022
���ӣ�https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/solutions/3637791/san-ci-xun-huan-by-tailuo022-kdio/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/