#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int w, int num) {
    int answer = 0;
    int row, col, numrow, numcol;
    if(n % w == 0){
        row = n / w;
        if(row % 2 == 0)
            col = 0;
        else
            col = w;
    }
    else{
        row = n / w + 1;
        if(row % 2 == 0)
            col = w + 1 - n % w;
        else
            col = n % w;
    }
    if(num % w == 0){
        numrow = num / w;
        if(numrow % 2 == 0)
            numcol = 0;
        else
            numcol = w;
    }
    else{
        numrow = num / w + 1;
        if(numrow % 2 == 0)
            numcol = w + 1 - num % w;
        else
            numcol = num % w;
    }
    if(row % 2 == 0){
        if(col > numcol)
            answer = row - numrow;
        else
            answer = row - numrow + 1;
    }
    else{
        if(col < numcol)
            answer = row - numrow;
        else
            answer = row - numrow + 1;
    }
    
    
    return answer;
}