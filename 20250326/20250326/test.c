

//2829.
int minimumSum(int n, int k) {
	int sum = 0;
	int count = 0;
	for (int i = 1; i <= k / 2 && count < n; i++) {
		sum += i;
		count++;
	}
	int start = k;
	while (count < n) {
		sum += start;
		start++;
		count++;
	}
	return sum;
}