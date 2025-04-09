

//3375.

/*
给你一个整数数组 nums 和一个整数 k 。
如果一个数组中所有 严格大于 h 的整数值都 相等 ，那么我们称整数 h 是 合法的 。
比方说，如果 nums = [10, 8, 10, 8] ，那么 h = 9 是一个 合法 整数，
	因为所有满足 nums[i] > 9 的数都等于 10 ，但是 5 不是 合法 整数。
你可以对 nums 执行以下操作：
选择一个整数 h ，它对于 当前 nums 中的值是合法的。
对于每个下标 i ，如果它满足 nums[i] > h ，那么将 nums[i] 变为 h 。
你的目标是将 nums 中的所有元素都变为 k ，请你返回 最少 操作次数。
如果无法将所有元素都变 k ，那么返回 -1 。
*/


int minOperations(int* nums, int numsSize, int k) {
	bool num[100] = { false };
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > k && num[nums[i]] == false) {
				num[nums[i]] = true;
				sum++;
		}
		if (nums[i] < k) {
			return -1;
		}
	}
	return sum;
}

/*

	问题等价为 当有小于 k 的值时返回 -1 ，否则统计大于 k 的不同的数字的个数。
	构建辅助数组，用来表明大于 k 的数字是否被访问过。
﻿
作者：tailuo022
链接：https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/solutions/3645466/bian-li-tong-ji-by-tailuo022-1n8y/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
