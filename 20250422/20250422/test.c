

//231.

/*
����һ������ n�������жϸ������Ƿ��� 2 ���ݴη�������ǣ����� true �����򣬷��� false ��
�������һ������ x ʹ�� n == 2x ������Ϊ n �� 2 ���ݴη���
*/

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPowerOfTwo(int n) {
    if (n <= 0)return false;
    return (n & (n - 1)) == 0;
}