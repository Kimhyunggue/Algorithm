#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int reverse(int n);

int main(){
    int a, b;
    scanf("%d %d",&a, &b);

    printf("%d",reverse(reverse(a)+reverse(b)));

    return 0;
}

int reverse(int n){
    int c = n;
    int i = 10;
    int j = 1;
    int num[10];
    int k = 0;
    while(c / j != 0){
        num[k] = (c % i) / j;
        i *= 10;
        j *= 10;
        k++;
    }

    c = 0;

    for(int a = k - 1, m = 1; a >= 0; a--){
        c += num[a]*m;
        m *= 10;
    }

    return c;
}