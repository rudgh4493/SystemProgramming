#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s '별칭=실제명령어'\n", argv[0]);
        return 1;
    }

    // 예: alias ll='ls -l'
    char cmd[200];  // cmd 크기를 늘려서 긴 명령어를 처리할 수 있도록
    snprintf(cmd, sizeof(cmd), "alias \"%s\"", argv[1]);  // 큰따옴표로 감싸기
    system(cmd);  // 쉘에 alias 등록

    return 0;
}
