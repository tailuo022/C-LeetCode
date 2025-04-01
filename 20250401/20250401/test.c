

//2140.

/*
����һ���±�� 0 ��ʼ�Ķ�ά�������� questions ������ questions[i] = [pointsi, brainpoweri] ��
��������ʾһ���������һϵ����Ŀ������Ҫ ��˳�� ��Ҳ���Ǵ����� 0 ��ʼ���ν������
	���ÿ������ѡ�� ��� ���� ���� ������������� i ������ ���  pointsi �ķ�����
	�����㽫 �޷� ����������� brainpoweri �����⣨��ֻ�������������� brainpoweri �����⣩��
	������������� i ������Զ���һ���������ʹ�����ֲ�����
�ȷ�˵������ questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ��
������� 0 ������ˣ� ��ô����Ի�� 3 �֣����㲻�ܽ������ 1 �� 2 ��
������������� 0 ���ҽ������ 1 ���㽫��� 4 �ֵ��ǲ��ܽ������ 2 �� 3 ��
���㷵���ⳡ���������ܻ�õ� ��� ������
*/

long long max(long long a, long long b) {
	return a > b ? a : b;
}

long long min(long long a, long long b) {
	return a < b ? a : b;
}

long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
	long long* dp = (long long*)malloc(sizeof(long long) * (questionsSize + 1));
	memset(dp, 0, (questionsSize + 1) * sizeof(long long));
	for (int i = questionsSize - 1; i >= 0; i--) {
		dp[i] = max(dp[i + 1], questions[i][0] + dp[min(questionsSize, i + questions[i][1] + 1)]);
	}
	long long res = dp[0];
	return res;
}