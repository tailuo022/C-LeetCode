

//263.

/*
丑数 就是只包含质因数 2、3 和 5 的 正 整数。
给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
*/

bool isUgly(int n) {
	if (n == 0) {
		return false;
	}
	while (! (n % 2) ) {
		n /= 2;
	}
	while (!(n % 3)) {
		n /= 3;
	}	
	while (!(n % 5)) {
		n /= 5;
	}
	if (n == 1) {
		return true;
	}
	else {
		return false;
	}
}

/*
	特殊情况 n == 0，返回 false。
	三段 while 循环一个思路，只分析其中一个，其他两个类似分析。
	whlie ( ! ( n % 2) ) 分两种情况：
		1：n 是 2 的倍数，那么 n % 2 == 0；取反则为真，进入循环，将 n / 2 判断其是否为 2 的倍数；
		2：n 不是 2 的倍数，那么 n % 2 != 0；取反则为假，不进入循环，判断 n 是否为下一个数的倍数。
	如果他是 2, 3, 5 的倍数，那么不论他是三个中任意那些的倍数，最后在整除之后的结果都为 1。
	反之，如果他不是 2, 3，5的倍数，那么他在进行三次循环之后就不为 1（对立事件)。

作者：tailuo022
链接：https://leetcode.cn/problems/ugly-number/solutions/3660068/qu-mod-zai-by-tailuo022-2qul/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/