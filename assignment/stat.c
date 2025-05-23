#include <stdio.h>          // 입출력을 위한 헤더
#include <sys/stat.h>       // 파일 상태를 확인하는 구조체와 함수 포함
#include <time.h>           // 시간 출력을 위한 헤더
//  파일 상태 확인
int main(int argc, char *argv[]) {
    struct stat fileStat;  // 파일 상태 정보를 저장할 구조체

    // 사용자 입력 확인: 파일명을 반드시 1개 인자로 받아야 함
    if (argc != 2) {
        printf("사용법: %s 파일명\n", argv[0]);  // 올바른 사용법 안내
        return 1;  // 오류 반환
    }

    // stat 함수로 파일 상태 정보 조회
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat 실패");  // 오류 발생 시 에러 메시지 출력
        return 1;
    }

    // 파일 크기 출력
    printf("파일 크기: %ld 바이트\n", fileStat.st_size);

    // 파일 권한 출력 (하위 9비트만 표시: rwxrwxrwx에 해당)
    printf("파일 권한: %o (8진수)\n", fileStat.st_mode & 0777);

    // 파일의 소유자 UID 출력
    printf("소유자 UID: %d\n", fileStat.st_uid);

    // 디바이스 ID 출력 (파일이 위치한 장치 식별자)
    printf("디바이스 ID: %ld\n", fileStat.st_dev);

    // 마지막 접근 시간 출력 (ctime 함수로 읽기 좋은 문자열로 변환)
    printf("마지막 접근 시간: %s", ctime(&fileStat.st_atime));

    // 마지막 수정 시간 출력
    printf("마지막 수정 시간: %s", ctime(&fileStat.st_mtime));

    return 0;  // 정상 종료
}
