#include <stdio.h>
#include <stdlib.h>

void backtracking(int depth);
int N, M;
int* selected;
int* arr;

int main(){
    scanf("%d %d",&N, &M);
    arr = (int*)malloc(sizeof(int)*M);
    selected = (int*)malloc(sizeof(int)*M);

    backtracking(0);

    return 0;
}

void backtracking(int depth) {
    if (depth == M) {
        for (int i=0; i<M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i=0; i<N; i++) {
        if (selected[i]!=1) {
            selected[i]=1;
            arr[depth] = i+1;
            backtracking(depth+1);
            selected[i]=0;
        }
    }
}