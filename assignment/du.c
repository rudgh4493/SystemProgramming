#include <stdio.h>         // 표준 입출력
#include <sys/stat.h>      // stat 함수와 구조체
// 디렉토리/파일 별 용량 확인
int main(int argc, char *argv[]) {
    struct stat st;        // 파일 상태 저장용 구조체

    // 인자가 부족할 경우 사용법 안내
    if (argc != 2) {
        printf("사용법: %s 파일명\n", argv[0]);
        return 1;
    }

    // 파일 상태 정보 얻기
    if (stat(argv[1], &st) == -1) {
        perror("stat 실패");
        return 1;
    }

    // st_blocks는 512바이트 단위 블록 수이므로 실제 사용 바이트로 환산
    // du와 동일하게 1K 단위로 출력하려면 st_blocks / 2
    printf("%ld\t%s\n", st.st_blocks / 2, argv[1]);

    return 0;
}
