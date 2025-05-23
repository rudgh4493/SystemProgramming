#include <stdio.h>
#include <libgen.h>  // dirname 함수 포함
// 경로에서 디렉토리명 추출
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s <경로>\n", argv[0]);
        return 1;
    }

    // dirname은 경로에서 디렉토리 경로만 추출
    printf("디렉토리 이름: %s\n", dirname(argv[1]));
    return 0;
}
