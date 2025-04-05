#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
    int num;
}Info;

int compare(void* a, void* b);

int main(){
    int N;
    scanf("%d",&N);
    Info* people = (Info*)malloc(sizeof(Info)*N);
    for (int i=0;i<N;i++) {
        scanf("%d %s",&(people[i].age),&(people[i].name));
        people[i].num = i;
    }

    qsort(people, N, sizeof(Info), compare);

    for (int i=0;i<N;i++)
        printf("%d %s\n",people[i].age, people[i].name);

    return 0;
}

int compare(void* a, void* b) {
    if (((Info*)a)->age > ((Info*)b)->age)
        return 1;
    else if (((Info*)a)->age < ((Info*)b)->age)
        return -1;
    else if (((Info*)a)->num > ((Info*)b)->num)
        return 1;
    else if (((Info*)a)->num < ((Info*)b)->num)
        return -1;
    else
        return 0;
}