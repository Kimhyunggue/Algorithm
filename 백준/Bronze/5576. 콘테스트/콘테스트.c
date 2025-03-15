#include <stdio.h>
#include <stdlib.h>

int compare(void* a, void* b);

int main(){
    int W[10],K[10];
    for (int i=0;i<10;i++)
        scanf("%d",&W[i]);
    qsort(W,10,sizeof(int),compare);
    for (int j=0;j<10;j++)
        scanf("%d",&K[j]);
    qsort(K,10,sizeof(int),compare);
    int Wscore=0, Kscore=0;
    for (int n=0;n<3;n++) {
        Wscore+=W[n];
        Kscore+=K[n];
    }
    printf("%d %d",Wscore, Kscore);

    return 0;
}

int compare(void* a, void* b) {
    if (*(int*)a > *(int*)b)
        return -1;
    else if (*(int*)a < *(int*)b)
        return 1;
    else
        return 0;
}