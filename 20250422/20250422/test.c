

//231.

/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
*/

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPowerOfTwo(int n) {
    if (n <= 0)return false;
    return (n & (n - 1)) == 0;
}