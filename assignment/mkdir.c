#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
//  새 디렉토리 생성
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <디렉토리 이름>\n", argv[0]);
        return 1;
    }

    // 디렉토리 생성 (퍼미션 755)
    if (mkdir(argv[1], 0755) != 0) {
        perror("mkdir 오류");
        return 1;
    }

    printf("디렉토리 '%s' 생성됨\n", argv[1]);
    return 0;
}
