#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10  // 기본 출력할 줄 수
//  파일의 처음 몇 줄 출력
int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    int lines_to_print = DEFAULT_LINES;  // 출력할 줄 수
    int count = 0;
    char buffer[1024];

    // 인자 체크 (ex: head filename 또는 head -n 5 filename)
    if (argc == 2) {
        filename = argv[1];
    } else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
        lines_to_print = atoi(argv[2]);
        filename = argv[3];
    } else {
        fprintf(stderr, "사용법: %s [-n 줄수] 파일명\n", argv[0]);
        return 1;
    }

    fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 오류");
        return 1;
    }

    // 파일에서 한 줄씩 읽어 최대 lines_to_print 줄 출력
    while (fgets(buffer, sizeof(buffer), fp) != NULL && count < lines_to_print) {
        fputs(buffer, stdout);
        count++;
    }

    fclose(fp);
    return 0;
}
