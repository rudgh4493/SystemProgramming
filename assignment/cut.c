#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 필드 추출 (탭 또는 콤마 구분)
// 필드 구분자(delimiter)로 특정 열(column) 추출
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s <구분자> <필드번호>\n", argv[0]);
        return 1;
    }

    char *delim = argv[1];
    int field = atoi(argv[2]);
    char line[1024];

    // 표준 입력에서 한 줄씩 읽기
    while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, delim);
        int count = 1;

        while (token != NULL) {
            if (count == field) {
                printf("%s\n", token);
                break;
            }
            token = strtok(NULL, delim);
            count++;
        }
    }
    return 0;
}
