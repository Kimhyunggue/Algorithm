#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    char *word;
    struct TrieNode **children;
    int childCount;
    int capacity;
}trieNode;

trieNode *createNode(char *word);
void addChild(trieNode *parent, char *word);
trieNode *insert(trieNode *root, char *words[], int depth, int totalWords);
void printTrie(trieNode *root, int depth);


int main(){
    int N;
    scanf("%d",&N);

    trieNode *root = createNode("");

    for (int i=0; i<N; i++) {
        int K;
        scanf("%d",&K);

        char *words[K];
        for (int j=0; j<K; j++) {
            words[j] = (char*)malloc(sizeof(char)*16);
            scanf(" %s",words[j]);
        }

        insert(root, words, 0, K);

        for (int j=0; j<K; j++)
            free(words[j]);
    }

    printTrie(root, 0);

    return 0;
}

trieNode* createNode(char *word) {
    trieNode* node = malloc(sizeof(trieNode));
    node->word = strdup(word);
    node->childCount = 0;
    node->capacity = 10;
    node->children = (trieNode**)malloc(sizeof(trieNode)*10);

    return node;
}

void addChild(trieNode *parent, char *word) {
    if (parent->childCount >= parent->capacity) {
        parent->capacity *= 2;
        parent->children = (trieNode**)realloc(parent->children, sizeof(trieNode *)*parent->capacity);
    }

    parent->children[parent->childCount++] = createNode(word);
}

trieNode *insert(trieNode *root, char *words[], int depth, int totalWords) {
    if (depth == totalWords)
        return root;

    for (int i=0; i<root->childCount; i++) {
        if (strcmp(root->children[i]->word, words[depth]) == 0 )
            return insert(root->children[i], words, depth + 1, totalWords);
    }

    addChild(root, words[depth]);

    return insert(root->children[root->childCount - 1], words, depth + 1, totalWords);
}

void printTrie(trieNode *root, int depth) {
    for (int i=0; i<root->childCount-1; i++) {
        for (int j=i+1; j<root->childCount; j++) {
            if (strcmp(root->children[i]->word, root->children[j]->word) > 0) {
                trieNode *tmp = root->children[i];
                root->children[i] = root->children[j];
                root->children[j] = tmp;
            }
        }
    }

    for (int i=0; i<root->childCount; i++) {
        for (int j=0; j<depth; j++)
            printf("--");
        printf("%s\n",root->children[i]->word);
        printTrie(root->children[i], depth+1);
    }
}