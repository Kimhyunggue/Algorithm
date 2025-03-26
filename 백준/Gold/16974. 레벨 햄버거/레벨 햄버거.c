#include <stdio.h>
#include <stdlib.h>

long long int* size;
long long int* patty;
long long int Hamburger(int level, long long int x);

int main() {
    int N;
    scanf("%d",&N);
    size = (long long int*)malloc(sizeof(long long int)*(N+1));
    patty = (long long int*)malloc(sizeof(long long int)*(N+1));

    for (int i=0;i<=N;i++) {
        if (i==0) {
            size[i] = 1;
            patty[i] = 1;
        }
        else {
            size[i] = 2 * size[i-1] + 3;
            patty[i] = 2 * patty[i-1] + 1;
        }
    }
    long long int layer;

    scanf("%lld",&layer);

    if (size[N]<layer) {
        printf("불가능한 입력\n");
        return 0;
    }

    printf("%lld", Hamburger(N, layer));



    return 0;
}

long long int Hamburger(int level, long long int x) {
    if (level == 0) return 1;

    if (x==1) return 0;
    else if (x <= size[level-1] + 1)
        return Hamburger(level-1,x-1);
    else if (x == size[level-1] + 2)
        return patty[level-1] + 1;
    else if (x <= size[level-1] * 2 + 2)
        return patty[level-1] + 1 + Hamburger(level-1, x - size[level-1] - 2);
    else
        return patty[level];
}