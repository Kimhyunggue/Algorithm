#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
    // MM:SS 형식(6바이트: 2자리 분, 콜론, 2자리 초, 널 문자)
    char* answer = (char*)malloc(6 * sizeof(char));
    
    // 시간(초)으로 변환
    int v_len = (video_len[0] - '0') * 600 + (video_len[1] - '0') * 60 + (video_len[3] - '0') * 10 + (video_len[4] - '0');
    int cur = (pos[0] - '0') * 600 + (pos[1] - '0') * 60 + (pos[3] - '0') * 10 + (pos[4] - '0');
    int op_s = (op_start[0] - '0') * 600 + (op_start[1] - '0') * 60 + (op_start[3] - '0') * 10 + (op_start[4] - '0');
    int op_e = (op_end[0] - '0') * 600 + (op_end[1] - '0') * 60 + (op_end[3] - '0') * 10 + (op_end[4] - '0');
    
    // 초기 위치가 오프닝 구간에 있으면 op_e로 이동
    if (cur >= op_s && cur <= op_e) {
        cur = op_e;
    }
    
    // 명령어 처리
    for (size_t i = 0; i < commands_len; i++) {
        if (strcmp(commands[i], "next") == 0) {
            cur += 10; // 10초 앞으로
            if (cur > v_len) {
                cur = v_len; // 영상 길이 초과 시 끝으로
            }
            // 오프닝 구간 체크
            if (cur >= op_s && cur <= op_e) {
                cur = op_e;
            }
        } else if (strcmp(commands[i], "prev") == 0) {
            cur -= 10; // 10초 뒤로
            if (cur < 0) {
                cur = 0; // 0초 미만 시 처음으로
            }
            // 오프닝 구간 체크
            if (cur >= op_s && cur <= op_e) {
                cur = op_e;
            }
        }
    }
    
    // 초를 MM:SS 형식으로 변환
    int minutes = cur / 60;
    int seconds = cur % 60;
    snprintf(answer, 6, "%02d:%02d", minutes, seconds);
    
    return answer;
}