#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <디렉토리 경로>\n", argv[0]);
        return 1;
    }

    // 디렉토리 변경 시도
    if (chdir(argv[1]) != 0) {
        perror("chdir 오류");
        return 1;
    }

    // 변경된 디렉토리 경로 출력
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("현재 디렉토리: %s\n", cwd);
    } else {
        perror("getcwd 오류");
        return 1;
    }

    return 0;
}
