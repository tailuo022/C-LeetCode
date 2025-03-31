

//2278.

/*
	给你一个字符串 s 和一个字符 letter ，
	返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。
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
	统计 letter 在 字符串 s 中出现的次数。
*/