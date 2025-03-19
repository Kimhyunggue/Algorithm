#include <stdio.h>

int main(){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    if (N-M*K<=0) {
        if (N-M*(K-1)-1<=0)
            printf("%d %d",0, 0);
        else
            printf("%d %d",0, N-M*(K-1)-1);
    }

    else
        printf("%d %d",N - M*K, N - M*(K-1)-1);

    return 0;
}