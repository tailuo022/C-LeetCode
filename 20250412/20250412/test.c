

//3272.

/*
给你两个 正 整数 n 和 k 。

如果一个整数 x 满足以下条件，那么它被称为 k 回文 整数 。

x 是一个 回文整数 。
x 能被 k 整除。
如果一个整数的数位重新排列后能得到一个 k 回文整数 ，那么我们称这个整数为 好 整数。比方说，k = 2 ，那么 2020 可以重新排列得到 2002 ，2002 是一个 k 回文串，所以 2020 是一个好整数。而 1010 无法重新排列数位得到一个 k 回文整数。

请你返回 n 个数位的整数中，有多少个 好 整数。

注意 ，任何整数在重新排列数位之前或者之后 都不能 有前导 0 。比方说 1010 不能重排列得到 101 。


*/

typedef struct {
    char* key;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, const char* key) {
    HashItem* pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, const char* key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = strdup(key);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem** obj) {
    HashItem* curr = NULL, * tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->key);
        free(curr);
    }
}

int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

long long countGoodIntegers(int n, int k) {
    HashItem* dict = NULL;
    int base = (int)pow(10, (n - 1) / 2);
    int skip = n & 1;
    /* 枚举 n 个数位的回文数 */
    for (int i = base; i < base * 10; i++) {
        char s[16];
        sprintf(s, "%d", i);
        int len = strlen(s);
        for (int j = len - 1 - skip; j >= 0; j--) {
            s[len + (len - skip - 1 - j)] = s[j];
        }
        s[2 * len - skip] = '\0';
        long long palindromicInteger = atoll(s);
        /* 如果当前回文数是 k 回文数 */
        if (palindromicInteger % k == 0) {
            qsort(s, strlen(s), sizeof(char), compare);
            hashAddItem(&dict, s);
        }
    }

    long long* factorial = malloc((n + 1) * sizeof(long long));
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    long long ans = 0;
    for (HashItem* pEntry = dict; pEntry; pEntry = pEntry->hh.next) {
        int cnt[10] = { 0 };
        for (int j = 0; pEntry->key[j] != '\0'; j++) {
            cnt[pEntry->key[j] - '0']++;
        }
        /* 计算排列组合 */
        long long tot = (n - cnt[0]) * factorial[n - 1];
        for (int j = 0; j < 10; j++) {
            tot /= factorial[cnt[j]];
        }
        ans += tot;
    }

    free(factorial);
    hashFree(&dict);
    return ans;
}

