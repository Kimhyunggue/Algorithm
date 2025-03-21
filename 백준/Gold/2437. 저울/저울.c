#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(void* x, void* y);

int main() {
	int N, arr[5000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	qsort(arr, N, sizeof(int), compare);

	if (arr[0] > 1) {
		printf("1");
		return 0;
	}

	int sum = arr[0], i = 0;
	while (i < N) {
		if (arr[i + 1] - sum < 2)
			sum += arr[i + 1];
		else
			break;
		i++;
	}
	printf("%d", sum + 1);

	return 0;
}

int compare(void* x, void* y) {
	if (*(int*)x > *(int*)y)
		return 1;
	else if (*(int*)x < *(int*)y)
		return -1;
	else
		return 0;
}