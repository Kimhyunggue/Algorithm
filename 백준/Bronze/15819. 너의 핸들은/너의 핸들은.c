#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(void* a, void* b);

int main(){
    int N, I;
    scanf("%d %d",&N, &I);
    if (N < I)
        return 0;

    char** words = (char**)malloc(sizeof(char*)* N);

    for (int i = 0; i < N; i++)
        words[i] = (char*)malloc(sizeof(char)*21);

    for (int j=0; j<N; j++)
        scanf(" %s", words[j]);

    qsort(words,N,sizeof(char*),compare);

    printf("%s", words[I - 1]);

    return 0;
}

int compare(void* a, void* b) {
    if (strcmp(*(char**)a, *(char**)b) !=0)
        return strcmp(*(char**)a, *(char**)b);
    else if (strlen(*(char**)a) > strlen(*(char**)b))
        return -1;
    else if (strlen(*(char**)a) < strlen(*(char**)b))
        return 1;
    else
        return 0;
}