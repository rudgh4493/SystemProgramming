#include <stdio.h>        // 입출력
#include <stdlib.h>       // atoi 함수
#include <signal.h>       // kill 함수 및 시그널 정의
// 프로세스 종료
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s PID\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);  // 문자열을 정수(PID)로 변환

    // SIGTERM(기본 종료 시그널) 보내기
    if (kill(pid, SIGTERM) == -1) {
        perror("프로세스 종료 실패");
        return 1;
    }

    printf("PID %d 프로세스를 종료했습니다.\n", pid);
    return 0;
}
