

//2537.

/*
给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。
一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，
	那么称它是一个 好 子数组。
子数组 是原数组中一段连续 非空 的元素序列。
*/

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    }
    else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

/*
根据题目中对于好数组的定义，如果 nums[i..j] 是一个好数组，那么对于所有满足 j
 >j 的 j，nums[i..j
′中相同的值不会更少，所以 nums[i..j
也一定是一个好数组。
这就提示我们可以使用双指针的方法解决本题。我们枚举左指针 left 表示子数组的左边界，它的初始值为 0，\
    同时用右指针 right 表示子数组的右边界，它的初始值为 −1。对于当前枚举到的 left，我们需要不断向右移动 right，直到 nums[left..right] 是一个好数组。
在移动 right 的过程中，我们可以增量计算相同元素的数量：我们可以使用一个哈希映射 cnt 记录每一个子数组中的每一个元素，
    以及它出现的次数。让 right 向右移动时，相同元素的数量增加了 cnt[right]，随后需要将 cnt[right] 增加 1。待 right 移动完成后，
     根据上面的推论，以 left 为左边界的好子数组的数量即为 n−right，其中 n 是数组 nums 的长度。我们将这个值累加入最终的答案。

在这之后，当前的左边界 left 枚举完成，相同的元素数量会减少 cnt[left]−1，随后也需要将 cnt[left] 减少 1。
当所有的左边界都枚举完成后，即可得到最终的答案

作者：力扣官方题解
链接：https://leetcode.cn/problems/count-the-number-of-good-subarrays/solutions/3643775/tong-ji-hao-zi-shu-zu-de-shu-mu-by-leetc-uvcm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/