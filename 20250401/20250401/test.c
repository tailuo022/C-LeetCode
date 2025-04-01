

//2140.

/*
给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 。
这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），
	针对每个问题选择 解决 或者 跳过 操作。解决问题 i 将让你 获得  pointsi 的分数，
	但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）。
	如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作。
比方说，给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ：
如果问题 0 被解决了， 那么你可以获得 3 分，但你不能解决问题 1 和 2 。
如果你跳过问题 0 ，且解决问题 1 ，你将获得 4 分但是不能解决问题 2 和 3 。
请你返回这场考试里你能获得的 最高 分数。
*/

long long max(long long a, long long b) {
	return a > b ? a : b;
}

long long min(long long a, long long b) {
	return a < b ? a : b;
}

long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
	long long* dp = (long long*)malloc(sizeof(long long) * (questionsSize + 1));
	memset(dp, 0, (questionsSize + 1) * sizeof(long long));
	for (int i = questionsSize - 1; i >= 0; i--) {
		dp[i] = max(dp[i + 1], questions[i][0] + dp[min(questionsSize, i + questions[i][1] + 1)]);
	}
	long long res = dp[0];
	return res;
}

/*
	从左到右选择问题 和 从右到左选着问题 得到的最高分数是一致的。
	构建数组 dp 用来保存选着第 i 个问题所保存的分数。
	如果 从左往右看，每一个后面的状态就会依赖于前一次的选择，
		那么每一种后面的状态都考虑进去的话，情况就会变成一个十分复杂的树(可看其他题解，我看到有暴力剪枝)。
	但是 从右往左看的话，dp[i] 就已经保存了当前最大的分数(后序的分数都已经知道了)，
		那么两个选择就已经固定了，因为如果选择跳过第 i 题，dp[i] = dp[i + 1]，如果解决第 i 题，
		得到该题的分数 questions[i][0] 后就会跳过 question[i][1] 道题目，
		对第 i + questions[i][1] + 1 道题目进行判断，但是是从后面向前面看的，
		所以后面的状态是已知的，也就是获得第 i + questions[i][1] + 1 道题目的分数，
		其中的边界条件就是假设的第 question + 1 道题目分数为 0 。
﻿
	倒着求结果，边界条件 dp[questionsSize] = 0 
		(即模拟加上最后一道没有分数的题目，用来当数组下标越界，也就是需要跳过题目之后超过了题目原本的数量，
		此时用 0 分替代)，循环从 dp[questionsSize - 1] 开始，也就是最后一个问题开始，
		由这个思路可以知道最后一道题是一定会被选择做的，然后向前倒推，
		判断是选择了做第 i 道题(也就是跳过后面 questions[i][1] 道题目)，
		还是跳过这道题(得到 dp[i + 1] )可以得到更高的分数。
		一直判断到是否对第一个问题进行解答从而找到最大分数。
	从右往左看 和 从左往右看结果一致。注意这个就可以了。

作者：tailuo022
链接：https://leetcode.cn/problems/solving-questions-with-brainpower/solutions/3636594/dao-zhao-dong-tai-gui-hua-hou-xu-zhuang-kkzgl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/