#include <stdio.h>
#include <stdlib.h>

int **video;
void compressVideo(int x, int y, int N);
int checkSame(int x, int y, int size);

int main(){
    int N;
    scanf("%d",&N);

    video = (int**)malloc(sizeof(int*)*N);

    for (int i=0; i<N; i++)
        video[i] = (int*)malloc(sizeof(int)*N);

    char line[N+1];
    for (int j=0; j<N; j++) {
        scanf(" %s", line);
        for (int k=0;k<N;k++)
            video[j][k] = line[k] - '0';
    }


    compressVideo(0,0,N);

    return 0;
}

void compressVideo(int x, int y, int N) {
    if (checkSame(x,y,N)) {
        printf("%d",video[x][y]);
    }
    else {
        int newSize = N/2;
        printf("(");
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                compressVideo(x+i*newSize,y+j*newSize,newSize);
        printf(")");
    }
}

int checkSame(int x, int y, int size) {
    if (size==1)
        return 1;

    int first = video[x][y];
    for (int i=x;i<x+size;i++)
        for (int j=y;j<y+size;j++)
            if (first!=video[i][j])
                return 0;

    return 1;
}