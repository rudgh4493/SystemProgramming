#include <stdio.h>
#include <stdlib.h>
// 스크립트 실행 또는 설정 적용
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s 파일명\n", argv[0]);
        return 1;
    }

    // source 명령은 bash 내부 명령어라 system으로는 안 됨
    // 대신 `.`(점) 명령 사용
    char cmd[256];
    snprintf(cmd, sizeof(cmd), ". %s", argv[1]);
    system(cmd);

    return 0;
}
