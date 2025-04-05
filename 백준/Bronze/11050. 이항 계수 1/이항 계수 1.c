#include <stdio.h>

int main(){
    int N, K;
    scanf("%d %d",&N, &K);
    int x = 1, y = 1, z = 1;
    for (int i=1;i<=N;i++)
        x*=i;
    for (int j=1;j<=K;j++)
        y*=j;
    for (int a=1;a<=(N-K);a++)
        z*=a;
    printf("%d",x/(y*z));

    return 0;
}