#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {
    int answer = 0;
    int giftMatrix[50][50] = {0};
    int *getGifts = malloc(sizeof(int) * (int)friends_len);
    int *giveGifts = malloc(sizeof(int) * (int)friends_len);
    int *nextMonthGifts = malloc(sizeof(int) * (int)friends_len);
    
    for(int i=0; i<friends_len; i++){
        getGifts[i] = 0;
        giveGifts[i] = 0;
        nextMonthGifts[i] = 0;
    }
    
    for(int k=0; k<(int)gifts_len; k++){
        char gift_copy[30];
        strcpy(gift_copy,gifts[k]);
        
        char *sender = strtok(gift_copy, " ");
        char *receiver = strtok(NULL, " ");
        
        int a = 0, b = 0; // a는 주는 사람 인덱스, b는 받는 사람 인덱스 
        for(int j=0; j<friends_len; j++){
            if(strcmp(friends[j],sender) == 0){
                a = j;
                break;
            }
        }
        for(int j=0; j<friends_len; j++){
            if(strcmp(friends[j],receiver) == 0){
                b = j;
                break;
            }
        }
        giftMatrix[a][b]++;
        giveGifts[a]++;
        getGifts[b]++;
    }
     
    for(int i = 0; i < friends_len; i++){
        for(int j = 0; j < i; j++){
            if(giftMatrix[i][j] > giftMatrix[j][i])
                nextMonthGifts[i]++;
            else if(giftMatrix[i][j] < giftMatrix[j][i])
                nextMonthGifts[j]++;
            else{
                if((giveGifts[i]-getGifts[i]) > (giveGifts[j]-getGifts[j]))
                    nextMonthGifts[i]++;
                else if((giveGifts[i]-getGifts[i]) < (giveGifts[j]-getGifts[j]))
                    nextMonthGifts[j]++;
            }
        }
    }
    
    for(int m=0; m<friends_len; m++){
        if(answer < nextMonthGifts[m])
            answer = nextMonthGifts[m];
    }
   
    
    return answer;
}