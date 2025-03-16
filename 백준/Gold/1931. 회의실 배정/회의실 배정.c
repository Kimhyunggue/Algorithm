#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TIME {
	int start;
	int end;
}time;

int compare(void* x, void* y);

int main() {
	int N;
	scanf("%d", &N);
	time* ptr;
	ptr = (time*)malloc(sizeof(time) * N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &ptr[i].start, &ptr[i].end);

	qsort(ptr, N, sizeof(time), compare);

	int i = 0, j = 1;
	int cnt = 1;
	while (j < N) {
		if (ptr[i].end <= ptr[j].start) {
			i = j;
			cnt++;
		}
		j++;
	}
	printf("%d", cnt);

	return 0;
}

int compare(void* x, void* y) {
	if (((time*)x)->end > ((time*)y)->end)
		return 1;
	else if (((time*)x)->end < ((time*)y)->end)
		return -1;
	else {
		if (((time*)x)->start > ((time*)y)->start)
			return 1;
		else if (((time*)x)->start < ((time*)y)->start)
			return -1;
		else
			return 0;
	}
}