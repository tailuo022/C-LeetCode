
//10.01 合并排序的数组
void merge(int* A, int ASize, int m, int* B, int BSize, int n) {
    int sum = m + n;
    int* p = (int*)malloc(sizeof(int) * sum);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            p[k++] = A[i++];
        } else {
            p[k++] = B[j++];
        }
    }
    while (i < m) {
        p[k++] = A[i++];
    }
    while (j < n) {
        p[k++] = B[j++];
    }
    // 将合并后的结果复制回数组A，从末尾开始
    for (i = 0; i < sum; i++) {
        A[ASize - sum + i] = p[i];
    }
    free(p); // 释放动态分配的内存
}