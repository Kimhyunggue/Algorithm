#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int a, b;
    for (int i=0; i<T; i++) {
        scanf("%d %d",&a, &b);
        int num[4];
        int result = 1;
        for (int j=0; j<4; j++) {
            result = (result*a)%10;
            if (result == 0)
                num[j] = 10;
            else
                num[j] = result;
        }
        if (b%4 == 0)
            printf("%d\n",num[3]);
        else
            printf("%d\n",num[b%4-1]);
    }

    return 0;
}