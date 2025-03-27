﻿

//2712.

/*
给你一个下标从 0 开始、长度为 n 的二进制字符串 s ，你可以对其执行两种操作：
	选中一个下标 i 并且反转从下标 0 到下标 i（包括下标 0 和下标 i ）的所有字符，成本为 i + 1 。
	选中一个下标 i 并且反转从下标 i 到下标 n - 1（包括下标 i 和下标 n - 1 ）的所有字符，成本为 n - i 。
返回使字符串内所有字符 相等 需要的 最小成本 。
反转 字符意味着：如果原来的值是 '0' ，则反转后值变为 '1' ，反之亦然。
*/

#define MIN(a, b) (a) > (b) ? (b) : (a)

long long minimumCost(char* s) {
	long long res = 0;
	int len = strlen(s);
	for (int i = 0; i < len - 1; i++) {
		if (s[i] != s[i + 1]) {
			res += MIN(i + 1, len - i - 1);
		}
	}
	return res;
} 

/*
当 s[i] 和 s[i + 1] 不同时，不论是哪一种方法， 
	s[0]、s[1]、... 、s[i - 1] 之间的相邻关系不变(原来是相邻相同，操作后也是相邻相同，
	原本是相邻不同，操作后也是相邻不同)，s[i + 2]、s[i + 3]、... 、s[n - 1] 也是如此
依次比较相邻是否相等(即是否需要通过两种操作之一来将其变为相等)，
	若不相等，计算两种操作分别需要的代价，取其较小值加入代价。
第一次：为 s[0] 时，比较 s[0] 和 s[1] 不同时计算两种操作需要的代价，取较小值。
第二次：为 s[1] 时，由于 s[0] 和 s[1] 已经通过第一次将其在逻辑上相等(物理存储的内容依旧是原内容)，
	比较 s[1] 和 s[2]。当 s[1] 和 s[2] 相同时， s[0] = s[1] = s[2]；
	当 s[1] 和 s[2] 不同时，s[0] = s[1] != s[2]，进行一次操作，比较两次操作的代价，取较小值。
第三次：为 s[2] 时，由于 s[0] 和 s[1] 和 s[2] 已经通过前两次操作将其在逻辑上相等(物理存储的呢荣光依旧是原内容)，
	比较 s[2] 和 s[3]。当 s[2] 和 s[3] 相等时，s[0] = s[1] = s[2] = s[3]；
	当 s[2] 和 s[3] 不同时， s[0] = s[1] = s[2] != s[3]，进行一次操作，比较两次操作的代价，取最小值。
...
第n - 1次(最后一次)：为 s[n - 2]时，前面逻辑上全部相等，即 s[0] = s[1] = ... = s[n - 2], 
	比较 s[n - 2] 和 s[n - 1]，判断是否进行操作。
重复上述步骤，直至将数组遍历完全(逻辑上全部相等)。
由于每次都是取的可能发生的操作的较小代价，将所有小代价相加可得到最小代价和。
﻿
判断条件可以是 for (int i = 0; i < len; i++)，
	由于字符串以 '\0' 结尾，所以 s[n - 1](0 或者 1) 必然和 s[n]('\0')不同，
	进行一次操作，得到进行第二种操作，即 s[n] 变换(且不论变为什么，因为题目没讲)，
	其较小代价为 len - (len - 1) - 1 = 0 (i = len - 1)，不影响结果，但不推荐。

	作者：tailuo022
	链接：https ://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/solutions/3629970/tan-xin-bian-li-mo-ni-by-tailuo022-t7pp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/