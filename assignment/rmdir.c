#include <stdio.h>
#include <unistd.h>
//  빈 디렉토리 삭제
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <디렉토리 이름>\n", argv[0]);
        return 1;
    }

    // 디렉토리 삭제 시도 (비어있어야 성공)
    if (rmdir(argv[1]) != 0) {
        perror("rmdir 오류");
        return 1;
    }

    printf("디렉토리 '%s' 삭제됨\n", argv[1]);
    return 0;
}
