
//2829.

/*
给你两个整数 n 和 k 。
对于一个由 不同 正整数组成的数组，
如果其中不存在任何求和等于 k 的不同元素对，则称其为 k - avoiding 数组。
返回长度为 n 的 k - avoiding 数组的可能的最小总和。
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
整体思路：由于求最小可能，在求和为 k 的情况下，
	将其分组为[1, k - 1]、[2, k -2]、... 、[k / 2 - 1, k / 2 + 1]、[k / 2,  k / 2]。
	其中取左边(1，2，... ，k / 2 - 1，k / 2)为数组元素，
	若数组没有填满，再从k，k+1，... 依次填满数组。
代码：i <= k / 2 && count < n。
	前者是取完了所有小于k的值但数组没有填满，
	之后的 count < n 负责把数组剩下的位子填上。后者是还没有到 k 的一般但是数组已经满了，直接输出。

作者：tailuo022
链接：https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/solutions/3628571/onshi-jian-zhao-chu-shu-zu-quan-bu-nei-r-gdv2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/