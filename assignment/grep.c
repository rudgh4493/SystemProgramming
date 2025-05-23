#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
// 문자열 검색
int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *filename;
    char *search_str;

    // 인자: 프로그램명, 검색할 문자열, 파일명
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 검색할_문자열 파일명\n", argv[0]);
        return 1;
    }

    search_str = argv[1];
    filename = argv[2];

    fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    // 파일을 한 줄씩 읽으면서 search_str 포함 여부 검사
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, search_str) != NULL) {
            // 문자열이 포함된 줄 출력
            fputs(buffer, stdout);
        }
    }

    fclose(fp);
    return 0;
}
