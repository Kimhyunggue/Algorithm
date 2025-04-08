#include <stdio.h>
#include <stdlib.h>

int compare(void *a, void *b);
void combination(int start, int depth);

int height[9];
int selected[7];
int find=0;

int main(){
    for (int i=0; i<9; i++)
        scanf("%d",&height[i]);

    qsort(height, 9, sizeof(int), compare);

    combination(0,0);

    return 0;
}

int compare(void *a, void *b) {
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

void combination(int start, int depth) {
    if (depth == 7) {
        int sum = 0;
        for (int i=0; i<7; i++)
            sum+= height[selected[i]];
        if (find == 1)
            return;
        if (sum!=100)
            return;
        else {
            for (int i=0; i<7; i++)
                printf("%d\n",height[selected[i]]);
            find = 1;
            return;
        }
    }
    else {
        for (int i=start; i<9; i++) {
            selected[depth] = i;
            combination(i+1, depth+1);
        }
    }
}