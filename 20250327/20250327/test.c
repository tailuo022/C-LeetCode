

//2712.

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