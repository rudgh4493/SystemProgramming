#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAX_LINES 1000  // 최대 저장 가능한 줄 수
//  파일의 마지막 몇 줄 출력
int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    int lines_to_print = DEFAULT_LINES;
    char *lines[MAX_LINES];  // 줄 저장용 포인터 배열
    int count = 0;
    char buffer[1024];

    // 인자 처리 (tail filename 또는 tail -n 5 filename)
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

    // 파일의 모든 줄을 읽어 동적 할당 후 저장
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (count < MAX_LINES) {
            lines[count] = strdup(buffer);  // 줄 복사
            if (lines[count] == NULL) {
                fprintf(stderr, "메모리 할당 오류\n");
                fclose(fp);
                return 1;
            }
            count++;
        } else {
            fprintf(stderr, "파일이 너무 큽니다.\n");
            break;
        }
    }
    fclose(fp);

    // 마지막 lines_to_print 줄 출력
    int start = count - lines_to_print;
    if (start < 0) start = 0;
    for (int i = start; i < count; i++) {
        fputs(lines[i], stdout);
        free(lines[i]);  // 할당 해제
    }

    return 0;
}
