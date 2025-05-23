#include <stdio.h>
#include <stdlib.h>
// 명령어 별칭 설정
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s '별칭=실제명령어'\n", argv[0]);
        return 1;
    }

    // 예: alias ll='ls -l'
    char cmd[100];
    snprintf(cmd, sizeof(cmd), "alias %s", argv[1]);
    system(cmd);  // 쉘에 alias 등록

    return 0;
}
