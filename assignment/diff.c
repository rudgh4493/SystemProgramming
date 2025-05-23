#include <stdio.h>
#include <string.h>
// 두 파일의 차이 비교
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s <파일1> <파일2>\n", argv[0]);
        return 1;
    }

    // 두 파일 열기
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    if (!f1 || !f2) {
        perror("파일 열기 실패");
        return 1;
    }

    char line1[1024], line2[1024];
    int lineno = 1;  // 줄 번호 카운터

    // 두 파일에서 각각 한 줄씩 읽으면서 비교
    while (fgets(line1, sizeof(line1), f1) && fgets(line2, sizeof(line2), f2)) {
        if (strcmp(line1, line2) != 0) {
            // 내용이 다를 경우 출력
            printf("다름 (줄 %d):\n< %s> %s\n", lineno, line1, line2);
        }
        lineno++;
    }

    // fclose로 파일 닫기
    fclose(f1);
    fclose(f2);
    return 0;
}
