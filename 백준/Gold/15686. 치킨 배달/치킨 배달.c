#include <limits.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}point;

point house[100];
int houseCount = 0;

point chicken[13];
int chickenCount = 0;
int N, M;
int min = INT_MAX;
int selected[13];

void combination(int start, int depth);
void calCityChickenDistance();

int main(){
    scanf("%d %d",&N, &M);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int num;
            scanf("%d",&num);
            if (num==1) {
                house[houseCount].x = i;
                house[houseCount++].y = j;
            }
            if (num==2) {
                chicken[chickenCount].x = i;
                chicken[chickenCount++].y = j;
            }
        }
    }

    combination(0, 0);

    printf("%d",min);

    return 0;
}

void combination(int start, int depth) {
    if (depth == M) {
        calCityChickenDistance();
        return;
    }

    for (int i = start; i < chickenCount; i++) {
        selected[depth] = i;
        combination(i+1, depth+1);
    }
}

void calCityChickenDistance() {
    int distance = 0;
    int cur;
    for (int i=0; i<houseCount; i++) {
        int minDis = INT_MAX;
        for (int j=0; j<M; j++) {
            cur = abs(house[i].x - chicken[selected[j]].x) + abs(house[i].y - chicken[selected[j]].y);
            if (minDis > cur)
                minDis = cur;
        }
        distance += minDis;
    }
    if (min > distance)
        min = distance;
}