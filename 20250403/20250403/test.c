

//2874.

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
	long long imax = 0;
	long long ijmax = 0;
	long long res = 0;
	for (int k = 0; k < numsSize; k++) {
		res = max(res, ijmax * nums[k]);
		ijmax = max(ijmax, imax - nums[k]);
		imax = max(imax, nums[k]);
	}
	return res;
}

/*
 始终记住需要满足条件 i < j < k。
	主要思路为要想结果最大，那么算术式左边和右边都要去最大值，而左边取最大值又需要 i 取最大值。
	满足 i < j < k ，所以当我们固定 k 的时候先更新 i 的最大值，然后更新 j 的值，
		最后再更新 k 的值(更新 res 的值是等价的)。代码先计算 res 也是为了满足 i < j < k ，
		如果先 imax 的代码在前面，那么此时的 i > k，不满足条件，ijmax 的位置是同理的，
		都是为了满足 i < j < k。然后依次更新得到最大值。
	至于为什么要固定 k ，因为这样的话，只需在 k 之前的元素中找 i 和 j，
		天然满足 i < j < k 的顺序，而且空间复杂度为O(1)。
﻿

作者：tailuo022
链接：https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/solutions/3639525/tan-xin-by-tailuo022-yyu4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/