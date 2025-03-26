#include <stdio.h>
#include <stdlib.h>

int minusOne = 0, zero = 0, one = 0;
int **paper;
int count[3] = {0,0,0};
void countPapers(int x, int y, int N);
int checkSame(int x, int y, int size);

int main(){
    int N;
    scanf("%d",&N);
    paper = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++)
        paper[i] = (int*)malloc(sizeof(int)*N);

    for (int j=0;j<N;j++)
        for (int k=0;k<N;k++)
            scanf("%d",&paper[j][k]);

    countPapers(0,0,N);
    printf("%d\n%d\n%d",count[0],count[1],count[2]);

    return 0;
}

void countPapers(int x, int y, int N) {
    if (checkSame(x, y, N)) {
        count[paper[x][y] + 1]++;
        return;
    }
    int newsize = N/3;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            countPapers(x+i*newsize, y+j*newsize, newsize);
}

int checkSame(int x, int y, int size) {
    if (size==1)
        return 1;

    int first = paper[x][y];
    for (int i=x;i<x+size;i++)
        for (int j=y;j<y+size;j++)
            if (paper[i][j]!=first) return 0;

    return 1;
}