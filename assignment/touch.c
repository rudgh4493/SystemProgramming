#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
//  현재 작업 디렉토리 경로 출력
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일 이름>\n", argv[0]);
        return 1;
    }

    // 파일 생성 (이미 있으면 열기)
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("파일 열기/생성 오류");
        return 1;
    }

    close(fd);  // 파일 닫기
    printf("파일 '%s' 생성 또는 열기 완료\n", argv[1]);
    return 0;
}
