#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int L, C;
char words[16];
char result[16];
int compare(const void* a, const void* b);
int is_vowel(char c);
void backtrack(int index, int depth, int vowels, int consonants);

int main(){
    scanf("%d %d", &L, &C);

    for(int i = 0; i < C; i++)
        scanf(" %c", &words[i]);

    qsort(words, C, sizeof(char), compare);

    backtrack(0, 0, 0, 0);

    return 0;
}

int compare(const void* a, const void* b){
    return (*(char*) a - *(char*) b);
}

int is_vowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
        return 0;
}

void backtrack(int index, int depth, int vowels, int consonants){
    if (depth == L){
        if(vowels >= 1 && consonants >= 2){
            result[L] = '\0';
            printf("%s\n", result);
        }
        return;
    }

    for (int i = index; i < C; i++){
        result[depth] = words[i];

        if(is_vowel(words[i]))
            backtrack(i + 1, depth + 1, vowels + 1, consonants);
        else
            backtrack(i + 1, depth + 1, vowels, consonants + 1);
    }
}