#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct {
    int to;
    struct Node* next;
} Node;

Node* adj[MAX];
int parent[MAX];
int visited[MAX];

void addEdge(int a, int b);
void BFS(int start);

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }

    BFS(1);

    for (int i = 2; i <= N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}

void addEdge(int a, int b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = b;
    newNode->next = adj[a];
    adj[a] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->to = a;
    newNode->next = adj[b];
    adj[b] = newNode;
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int cur = queue[front++];
        Node* temp = adj[cur];

        while (temp) {
            int next = temp->to;
            if (!visited[next]) {
                parent[next] = cur;
                visited[next] = 1;
                queue[rear++] = next;
            }
            temp = temp->next;
        }
    }
}