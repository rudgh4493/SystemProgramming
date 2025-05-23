#include <stdio.h>
#include <ctype.h>
// 단어, 라인, 바이트 수 세기
int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    int lines = 0, words = 0, bytes = 0;
    int c, in_word = 0;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일명\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    // 파일을 한 문자씩 읽으면서 카운팅
    while ((c = fgetc(fp)) != EOF) {
        bytes++;

        if (c == '\n') {
            lines++;  // 줄 수 증가
        }

        // 단어는 공백이 아닌 연속 문자 단위
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;  // 새로운 단어 시작
        }
    }

    fclose(fp);

    printf("줄 수: %d\n", lines);
    printf("단어 수: %d\n", words);
    printf("바이트 수: %d\n", bytes);

    return 0;
}
