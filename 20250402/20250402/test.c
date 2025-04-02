

//2873.

/*
给你一个下标从 0 开始的整数数组 nums 。
请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。
	如果所有满足条件的三元组的值都是负数，则返回 0 。
下标三元组 (i, j, k) 的值等于 (nums[i] - nums[j]) * nums[k] 。
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
简单题就是要用简单的解法(
	三次循环枚举所有情况，比较保存最大值。
	可能的问题：
		需要将其中一个 int 强制转换为 long long 类型，后续的运算由于整型提升，
			全部化为 long long 类型进行运算，先进行运算再强制转换为 long long 类型的话，
			如果计算结果溢出 int 的范围的话，在算术式得到结果的那一刻，就发生了截断
			(将保存不下的位置去掉，去数字高位)，此时在进行强制类型转换，
			就是把已经截断的的结果整型提升，保存的是错误的结果。
	使用自带的比较函数就没有这个问题，不过是简单题(初学者)，还是多会一点知识的好(

作者：tailuo022
链接：https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/solutions/3637791/san-ci-xun-huan-by-tailuo022-kdio/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/