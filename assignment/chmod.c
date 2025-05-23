#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
//  파일 권한 변경
int main(int argc, char *argv[]) {
    char *mode_str;
    char *filename;
    mode_t mode;

    // 사용법: chmod 755 파일명
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 권한(8진수) 파일명\n", argv[0]);
        return 1;
    }

    mode_str = argv[1];
    filename = argv[2];

    // 8진수 문자열을 숫자로 변환
    mode = strtol(mode_str, NULL, 8);
    if (mode == 0) {
        fprintf(stderr, "잘못된 권한 형식\n");
        return 1;
    }

    // chmod 함수 호출하여 권한 변경
    if (chmod(filename, mode) == -1) {
        perror("chmod 실패");
        return 1;
    }

    printf("파일 '%s' 권한이 %s(8진수)로 변경되었습니다.\n", filename, mode_str);
    return 0;
}
