#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    struct Node* front;
    int num;
    int value;
    struct Node* rear;
}node;

node* initList(int data);
void addList(node* head, int data, int i);
void finList(node* head);
node* delList(node* head, int* cnt);

int main() {
    int N, data;
    node* head = NULL;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d",&data);
        if (i==0)
            head = initList(data);
        else
            addList(head, data, i+1);
    }
    finList(head);
    int cnt = 0;
    while (head != NULL)
        head = delList(head, &cnt);


    return 0;
}

node* initList(int data) {
    node* head = (node*)malloc(sizeof(node));
    head->front = NULL;
    head->value = data;
    head->num = 1;
    head->rear = NULL;

    return head;
}

void addList(node* head, int data, int i) {
    if (head->rear == NULL) {
        node* cur = (node*)malloc(sizeof(node));
        head->rear = cur;
        cur->value = data;
        cur->num = i;
        cur->front = head;
        cur->rear = NULL;
    }
    else {
        node* cur = head;
        while (cur->rear != NULL)
            cur = cur->rear;
        node* newNode = (node*)malloc(sizeof(node));
        newNode->front = cur;
        cur->rear = newNode;
        newNode->num = i;
        newNode->value = data;
        newNode->rear = NULL;
    }
}

void finList(node* head) {
    if (head == NULL)
        return;
    else if (head->rear == NULL)
        return;
    else {
        node* cur = head;
        while (cur->rear != NULL)
            cur = cur->rear;
        cur->rear = head;
        head->front = cur;
    }
}

node* delList(node* head, int* cnt) {
    if (head == NULL)
        return NULL;

    printf("%d ", head->num);
    node* cur = head;
    int move = head->value;

    if (head->rear == head) {  // 마지막 노드 처리
        free(head);
        return NULL;
    }

    head->front->rear = head->rear;
    head->rear->front = head->front;

    if (move > 0) {
        for (int i = 0; i < move; i++)
            cur = cur->rear;
    } else {
        for (int i = 0; i < abs(move); i++)
            cur = cur->front;
    }

    free(head);
    return cur;
}