#include <stdio.h>            // 표준 입출력 함수
#include <sys/statvfs.h>      // 파일 시스템 관련 정보를 위한 헤더
//  디스크 사용량 확인
int main() {
    struct statvfs stat;      // 파일 시스템 정보를 담는 구조체

    // 현재 디렉토리 (".")의 파일 시스템 통계 정보 얻기
    if (statvfs(".", &stat) != 0) {
        perror("statvfs 실패");  // 실패 시 오류 출력
        return 1;
    }

    // 전체 블록 수 × 블록 크기 = 전체 용량
    unsigned long total = stat.f_blocks * stat.f_frsize;

    // 사용 가능한 블록 수 × 블록 크기 = 여유 공간
    unsigned long free = stat.f_bfree * stat.f_frsize;

    // 정보 출력
    printf("전체 디스크 용량: %lu 바이트\n", total);
    printf("사용 가능한 공간: %lu 바이트\n", free);
    printf("사용 중인 공간: %lu 바이트\n", total - free);

    return 0;
}
