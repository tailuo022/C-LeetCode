
//504. Æß½øÖÆÊý
char* convertToBase7(int num) {
	if (num == 0) {
		return "0";
	}
	char* ret = (char*)malloc(sizeof(char) * 32);
	int neg = 0;
	if (num < 0) {
		neg = 1;
		num = -num;
	}
	int pos = 0;
	while (num > 0) {
		ret[pos++] = num % 7 + '0';
		num /= 7;
	}
	if (neg) {
		ret[pos++] = '-';
	}
	for (int i = 0; 2 * i < pos - 1; i++) {
		char c = ret[i];
		ret[i] = ret[pos - 1 - i];
		ret[pos - 1 - i] = c;
	}
	ret[pos] = '\0';
	return ret;
}