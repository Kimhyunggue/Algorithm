#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int start;
    long long int end;
}time;

typedef struct {
    long long int* heap;
    int size;
}MinHeap;

int compare(void* a, void* b);
void push(MinHeap* head, long long int value);
long long int pop(MinHeap* head);

int main(){
    int N;
    scanf("%d",&N);
    time* table = malloc(sizeof(time)*N);
    for (int i=0;i<N;i++)
        scanf("%lld %lld",&table[i].start,&table[i].end);

    qsort(table, N, sizeof(time), compare);

    MinHeap a;
    a.heap = (long long int*)malloc(sizeof(long long int)* N);
    a.size = 0;

    push(&a, table[0].end);

    for (int i=1; i<N; i++) {
        if (a.heap[0] <= table[i].start)
            pop(&a);
        push(&a, table[i].end);
    }

    printf("%d",a.size);

    free(table);
    free(a.heap);

    return 0;
}

int compare(void* a , void* b) {
    if ((*(time*)a).start > (*(time*)b).start)
        return 1;
    else if (((*(time*)a).start < (*(time*)b).start))
        return -1;
    else if ((*(time*)a).end > (*(time*)b).end)
        return 1;
    else if ((*(time*)a).end < (*(time*)b).end)
        return -1;
    else
        return 0;
}

void push(MinHeap* head, long long int value) {
    head->heap[head->size++] = value;
    int i = head->size - 1;
    while (i > 0 && head->heap[i] < head->heap[(i-1)/2]) {
        long long int tmp = head->heap[i];
        head->heap[i] = head->heap[(i-1)/2];
        head->heap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

long long int pop(MinHeap* head) {
    long long int cur = head->heap[0];
    head->heap[0] = head->heap[--head->size];
    int i = 0;
    while (2*i + 1 < head->size) {
        int left = 2*i+1, right = 2*i+2;
        int minIndex = left;
        if (right < head->size && head->heap[right] < head->heap[left])
            minIndex = right;
        if (head->heap[i] < head->heap[minIndex])
            break;
        long long int tmp = head->heap[i];
        head->heap[i] = head->heap[minIndex];
        head->heap[minIndex] = tmp;
        i = minIndex;
    }
    return cur;
}