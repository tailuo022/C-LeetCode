/*
给你一个下标从 0 开始的字符串 s ，重复执行下述操作 任意 次：
	在字符串中选出一个下标 i ，并使 c 为字符串下标 i 处的字符。
	并在 i 左侧（如果有）和 右侧（如果有）各 删除 一个距离 i 最近 的字符 c 。
请你通过执行上述操作任意次，使 s 的长度 最小化 。
返回一个表示 最小化 字符串的长度的整数。
*/



//2716.
int minimizedStringLength(char* s) {
	int len = strlen(s);
	int test[26] = { 0 };
	for (int i = 0; i < len; i++) {
		test[s[i] - 'a'] = 1;
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		res += test[i];
	}
	return res;
}

/*
		设立一个辅助数组test[26]，大小为26个字母大小，初始值全为0。
		遍历串，将出现的字母对应的辅助数组空间标记为1(如 c 对应的空间为 c - 'a' = 2，即test[2] = 1 )；
	遍历完全后，数组test的总和就是不同字母数总和。
﻿

作者：tailuo022
链接：https://leetcode.cn/problems/minimize-string-length/solutions/3631591/zuo-biao-ji-tong-ji-bu-tong-zi-mu-shu-by-jigk/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/