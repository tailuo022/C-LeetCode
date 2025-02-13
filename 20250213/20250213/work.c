#define  _CRT_SECURE_NO_WARNINGS

// .1103 ·ÖÌÇ¹ûII

#include <stdio.h>

int* distributeCandies(int candies, int num_people, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * num_people);
	if (ans == NULL) {
		return NULL;
	}
	memset(ans, 0, sizeof(int) * num_people);
	*returnSize = num_people;
	int i = 1, j = 0;
	if (candies == 1) {
		ans[0] = 1;
		return ans;
	}
	while (candies > i) {
		for (j = 0; j < num_people && candies > i; j++) {
			ans[j] += i;
			candies -= i;
			++i;
		}
	}
	if (j > num_people - 1) {
		ans[0] += candies;
	}
	else {
		ans[j] += candies;
	}
	return ans;
}