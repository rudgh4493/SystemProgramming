#include <stdio.h>
#include <stdlib.h>
// 환경 변수 설정
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s VAR=VALUE\n", argv[0]);
        return 1;
    }

    // 환경 변수 설정 (export VAR=VALUE와 유사)
    putenv(argv[1]);

    // 설정된 값 확인
    printf("환경 변수 설정: %s\n", argv[1]);

    return 0;
}
