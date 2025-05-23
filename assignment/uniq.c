#include <stdio.h>
#include <string.h>
// 인접한 중복 줄 제거
int main() {
    char prev[1024] = "";        // 이전 줄을 저장할 문자열
    char curr[1024];             // 현재 입력 줄

    // 표준 입력에서 한 줄씩 읽는다
    while (fgets(curr, sizeof(curr), stdin)) {
        // 이전 줄과 현재 줄이 다를 경우에만 출력
        if (strcmp(curr, prev) != 0) {
            printf("%s", curr);       // 현재 줄 출력
            strcpy(prev, curr);       // 현재 줄을 이전 줄로 저장
        }
        // 같을 경우 출력하지 않음 (중복 제거 효과)
    }

    return 0;
}
