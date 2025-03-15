#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char univ[20];
    int data;
}node;

int main(){
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++) {
        int N;
        scanf("%d",&N);
        node* a = (node*)malloc(sizeof(node)*N);
        for (int j=0;j<N;j++)
            scanf("%s %d",&(a[j].univ),&(a[j].data));
        int max = 0, index = 0;
        for (int k=0; k<N; k++) {
            if (max <= a[k].data) {
                max = a[k].data;
                index = k;
            }
        }
        printf("%s\n",a[index].univ);
    }

    return 0;
}