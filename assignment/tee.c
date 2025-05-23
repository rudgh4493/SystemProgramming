#include <stdio.h>
// 표준 출력을 파일에도 동시에 저장
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    // 출력 내용을 저장할 파일 열기 (쓰기 모드)
    FILE *fp = fopen(argv[1], "w");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char buffer[1024];

    // 표준 입력에서 한 줄씩 읽음
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer);        // 터미널에 출력
        fprintf(fp, "%s", buffer);   // 파일에도 출력
    }

    fclose(fp);  // 파일 닫기
    return 0;
}
