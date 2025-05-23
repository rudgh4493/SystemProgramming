#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep 함수 포함
// 지정 시간만큼 대기
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s 초\n", argv[0]);
        return 1;
    }

    int sec = atoi(argv[1]);  // 문자열을 정수로 변환

    printf("%d초 동안 대기합니다...\n", sec);
    sleep(sec);  // 지정된 시간 동안 대기
    printf("대기가 끝났습니다.\n");

    return 0;
}
