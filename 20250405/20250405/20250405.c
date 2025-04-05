

//1863.

/*
一个数组的 异或总和 定义为数组中所有元素按位 XOR 的结果；如果数组为 空 ，则异或总和为 0 。
例如，数组 [2,5,6] 的 异或总和 为 2 XOR 5 XOR 6 = 1 。
给你一个数组 nums ，请你求出 nums 中每个 子集 的 异或总和 ，计算并返回这些值相加之 和 。
注意：在本题中，元素 相同 的不同子集应 多次 计数。
数组 a 是数组 b 的一个 子集 的前提条件是：从 b 删除几个（也可能不删除）元素能够得到 a 。
*/


// 递归计算所有子集的异或和
void dfs(int* nums, int numsSize, int index, int current, int* total) {
    if (index == numsSize) {
        *total += current;
        return;
    }
    // 包含当前元素
    dfs(nums, numsSize, index + 1, current ^ nums[index], total);
    // 不包含当前元素
    dfs(nums, numsSize, index + 1, current, total);
}

int subsetXORSum(int* nums, int numsSize) {
    int total = 0;
    dfs(nums, numsSize, 0, 0, &total);
    return total;
}

/*
dfs一条道走到黑。
    不多解释，递归这玩意，一般人讲不明白，我不一样，我是f5，所以我不讲。
    见代码：
    以[2, 5, 6]为例。
    dfs(nums, 3, 0, 0, &total)
﻿
初始调用层 (index=0, current_xor=0)
├─ 分支1：包含元素2 → index=1, current_xor=0^2=2
│  ├─ 分支1：包含元素5 → index=2, current_xor=2^5=7
│  │  ├─ 分支1：包含元素6 → index=3, current_xor=7^6=1 → 累加1到总和
│  │  └─ 分支2：不包含元素6 → index=3, current_xor=7 → 累加7到总和
│  └─ 分支2：不包含元素5 → index=2, current_xor=2
│     ├─ 分支1：包含元素6 → index=3, current_xor=2^6=4 → 累加4到总和
│     └─ 分支2：不包含元素6 → index=3, current_xor=2 → 累加2到总和
└─ 分支2：不包含元素2 → index=1, current_xor=0
   ├─ 分支1：包含元素5 → index=2, current_xor=0^5=5
   │  ├─ 分支1：包含元素6 → index=3, current_xor=5^6=3 → 累加3到总和
   │  └─ 分支2：不包含元素6 → index=3, current_xor=5 → 累加5到总和
   └─ 分支2：不包含元素5 → index=2, current_xor=0
      ├─ 分支1：包含元素6 → index=3, current_xor=0^6=6 → 累加6到总和
      └─ 分支2：不包含元素6 → index=3, current_xor=0 → 累加0到总和
﻿
    这是天才的壮举！
    递归太棒了！

作者：tailuo022
链接：https://leetcode.cn/problems/sum-of-all-subset-xor-totals/solutions/3641270/di-gui-bian-li-suo-you-zi-ji-bing-lei-ji-dhyb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/