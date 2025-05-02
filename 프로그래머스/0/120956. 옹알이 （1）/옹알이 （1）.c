#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    for(int i=0; i<babbling_len; i++){
        char word[20];
        int cnt = 0;
        int a=0, b=0, c=0, d=0;
        strcpy(word, babbling[i]);
        int len = strlen(babbling[i]);
        while(cnt < len){
            if(cnt + 3 <= len){
                if(strncmp(babbling[i]+cnt,"aya",3) == 0){
                    if(a==0){
                        a++;
                        cnt+=3;
                    }
                    else
                        break;
                }
                else if(strncmp(babbling[i]+cnt,"woo",3) == 0){
                    if(b==0){
                        b++;
                        cnt+=3;
                    }
                    else
                        break;
                }
                else if(strncmp(babbling[i]+cnt,"ye",2) == 0){
                    if(c==0){
                        c++;
                        cnt+=2;
                    }
                    else
                        break;
                }
                else if(strncmp(babbling[i]+cnt,"ma",2)==0){
                    if(d==0){
                        d++;
                        cnt+=2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else if(cnt + 2 <= len){
                if(strncmp(babbling[i]+cnt,"ye",2) == 0){
                    if(c==0){
                        c++;
                        cnt+=2;
                    }
                    else
                        break;
                }
                else if(strncmp(babbling[i]+cnt,"ma",2) == 0){
                    if(d==0){
                        d++;
                        cnt+=2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else
                break;
        }
        if(cnt == len)
            answer++;
    }
    
    return answer;
}