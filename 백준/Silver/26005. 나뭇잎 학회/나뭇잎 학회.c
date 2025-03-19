#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    if (N==1)
        printf("%d",0);
    else if (N%2==0)
        printf("%d",N*N/2);
    else
        printf("%d",N*N/2+1);

    return 0;
}