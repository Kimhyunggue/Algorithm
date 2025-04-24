#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// schedules_len은 배열 schedules의 길이입니다.
// timelogs_rows는 2차원 배열 timelogs의 행 길이, timelogs_cols는 2차원 배열 timelogs의 열 길이입니다.
int solution(int schedules[], size_t schedules_len, int** timelogs, size_t timelogs_rows, size_t timelogs_cols, int startday) {
    int answer = timelogs_rows;
    int curday = startday;
    for(int i=0; i<schedules_len; i++){
        if(schedules[i] % 100 >= 50)
            schedules[i] += 50;
        else
            schedules[i] += 10;
    }
    
    for(int i=0; i<timelogs_rows; i++){
        curday = startday;
        for(int j=0; j<timelogs_cols; j++){
            if(curday > 7)
                curday %= 7;
            if(curday != 6 && curday != 7){
                if(timelogs[i][j] > schedules[i]){
                    answer--;
                    break;
                }
            }
            curday++;
        }
    }
    
    return answer;
}