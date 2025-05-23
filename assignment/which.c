#include <stdio.h>         // 입출력
#include <stdlib.h>        // system 함수 사용
//  명령어의 경로 확인
int main(int argc, char *argv[]) {
    char command[100];     // 실행할 명령어 저장용

    if (argc != 2) {
        printf("사용법: %s 명령어\n", argv[0]);
        return 1;
    }

    // "which <명령어>" 명령어 문자열 만들기
    snprintf(command, sizeof(command), "which %s", argv[1]);
    system(command);  // 명령어 실행

    return 0;
}
