#include <stdio.h>
#include <libgen.h>  // basename 함수 포함
// 경로에서 파일명 추출
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s <경로>\n", argv[0]);
        return 1;
    }

    // basename은 경로에서 파일 이름만 추출
    printf("파일 이름: %s\n", basename(argv[1]));
    return 0;
}
