

//2109.

/*
����һ���±�� 0 ��ʼ���ַ��� s ��
	�Լ�һ���±�� 0 ��ʼ���������� spaces ��
���� spaces ����ԭ�ַ�������Ҫ��ӿո���±ꡣ
	ÿ���ո�Ӧ�ò��뵽�������������ַ�ֵ ֮ǰ ��

���磬s = "EnjoyYourCoffee" �� spaces = [5, 9] ��
	��ô������Ҫ�� 'Y' �� 'C' ֮ǰ��ӿո�
	�������ַ��ֱ�λ���±� 5 ���±� 9 ��
	��ˣ����յõ� "Enjoy Your Coffee" ��
������ӿո񣬲������޸ĺ���ַ�����
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
	����˫ָ�룬i ָ�� s �ַ�����j ָ�� spaces ����Ԫ�ء�
		������������ res ��СΪ s ���Ĵ�С���Ͽո��� + 1 (�� '\0' ��β)��
	ֱ�ӿ����롣
���ܵ����ʣ�
	A��Ϊʲô if ������治���� s ����
	���������Ҫ�� s ����ȫ�����ݿ����� res ���У��� spaces ������ֻ�ǽ��ո�������ĸ�λ�ã�
		Ҳ���ǲ岻���붼Ҫ����һ�Σ����ǲ����� if �������һ�� res[k++] = s[i++]�������� if else �����ж�����жϡ�
	B��Ϊʲô����һ�� while��
	�� s ��ʣ�µ����ݿ����� res ���У������� ����ϲ�������� while��

���ߣ�tailuo022
���ӣ�https://leetcode.cn/problems/adding-spaces-to-a-string/solutions/3633623/shuang-zhi-zhen-by-tailuo022-dgxg/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/