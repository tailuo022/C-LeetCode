

//2109.

/*
给你一个下标从 0 开始的字符串 s ，
	以及一个下标从 0 开始的整数数组 spaces 。
数组 spaces 描述原字符串中需要添加空格的下标。
	每个空格都应该插入到给定索引处的字符值 之前 。

例如，s = "EnjoyYourCoffee" 且 spaces = [5, 9] ，
	那么我们需要在 'Y' 和 'C' 之前添加空格，
	这两个字符分别位于下标 5 和下标 9 。
	因此，最终得到 "Enjoy Your Coffee" 。
请你添加空格，并返回修改后的字符串。
*/

char* addSpaces(char* s, int* spaces, int spacesSize) {
	int num_string = strlen(s);
	int num_space = spacesSize;
	int i = 0, j = 0, k = 0;
	char* res = (char*)malloc(sizeof(char) * (num_space + num_string + 1));
	while (i < num_string && j < num_space) {
		if (i == spaces[j]) {
			res[k++] = ' ';
			j++;
		}
			res[k++] = s[i++];
	}
	while (i < num_string) {
		res[k++] = s[i++];
	}
	res[num_string + num_space] = '\0';
	return res;
}

/*
	构造双指针，i 指向 s 字符串，j 指向 spaces 数组元素。
		构建辅助数组 res 大小为 s 串的大小加上空格数 + 1 (以 '\0' 结尾)。
	直接看代码。
可能的疑问：
	A：为什么 if 语句里面不处理 s 串？
	由于最后都是要将 s 串的全部内容拷贝到 res 串中，而 spaces 的内容只是酱空格插入在哪个位置，
		也就是插不插入都要拷贝一次，于是不用在 if 里面加上一个 res[k++] = s[i++]；并且用 if else 来进行额外的判断。
	B：为什么还有一个 while？
	将 s 串剩下的内容拷贝到 res 串中，类似于 链表合并后的两个 while。

作者：tailuo022
链接：https://leetcode.cn/problems/adding-spaces-to-a-string/solutions/3633623/shuang-zhi-zhen-by-tailuo022-dgxg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/