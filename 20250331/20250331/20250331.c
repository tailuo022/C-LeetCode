

//2278.

/*
	����һ���ַ��� s ��һ���ַ� letter ��
	������ s �е��� letter �ַ���ռ�� �ٷֱ� ������ȡ������ӽ��İٷֱȡ�
*/

int percentageLetter(char* s, char letter) {
	int sum = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		if (s[i] == letter)
			sum++;
	return sum * 100 / len;
}

/*
	ͳ�� letter �� �ַ��� s �г��ֵĴ�����
*/