#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int kor;
    int math;
    int eng;
}grade;

int compare(void* a, void* b);

int main(){
    int N;
    scanf("%d",&N);
    grade* a = (grade*)malloc(sizeof(grade)*N);
    for (int i=0;i<N;i++)
        scanf(" %s %d %d %d",a[i].name, &a[i].kor, &a[i].eng, &a[i].math);

    qsort(a, N, sizeof(grade), compare);

    for (int i=0;i<N;i++)
        printf("%s\n",a[i].name);

    return 0;
}

int compare(void* a, void* b) {
    if (((grade*)a)->kor > ((grade*)b)->kor)
        return -1;
    else if (((grade*)a)->kor < ((grade*)b)->kor)
        return 1;
    else if (((grade*)a)->eng > ((grade*)b)->eng)
        return 1;
    else if (((grade*)a)->eng < ((grade*)b)->eng)
        return -1;
    else if (((grade*)a)->math > ((grade*)b)->math)
        return -1;
    else if (((grade*)a)->math < ((grade*)b)->math)
        return 1;
    else
        return strcmp(((grade*)a)->name, ((grade*)b)->name);
}