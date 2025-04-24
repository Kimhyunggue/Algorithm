#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int w, int num) {
    int answer = 0;
    int m1 = num % (2*w);
    int m2 = ((2*w+1)-m1) % (2*w);
    for(int i=num; i<=n; i++){
        if(i%(2*w) == m1 || i%(2*w) == m2)
            answer++;
    }
    
    return answer;
}