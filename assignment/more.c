#include <stdio.h>
#include <stdlib.h>

#define PAGE_LINES 20  // 한 페이지에 출력할 줄 수
//  페이지 단위로 출력
int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    char buffer[1024];
    int line_count = 0;
    int c;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일명\n", argv[0]);
        return 1;
    }
    filename = argv[1];

    fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 오류");
        return 1;
    }

    // 한 줄씩 출력하면서 PAGE_LINES마다 멈춤
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fputs(buffer, stdout);
        line_count++;

        if (line_count == PAGE_LINES) {
            printf("--더 보려면 스페이스 누르세요--\n");
            c = getchar();  // 사용자 입력 대기
            if (c != ' ') {  // 스페이스 외에는 종료
                break;
            }
            line_count = 0;  // 페이지 카운트 초기화
        }
    }

    fclose(fp);
    return 0;
}
