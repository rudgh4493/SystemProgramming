#include <stdio.h>        // 표준 입출력
#include <stdlib.h>       // 표준 라이브러리 함수
//  실시간 시스템 리소스 상태 보기
int main() {
    FILE *fp = fopen("/proc/loadavg", "r");  // 로드 평균 정보 파일 열기
    if (!fp) {
        perror("loadavg 파일 열기 실패");
        return 1;
    }

    double load1, load5, load15;

    // 1분, 5분, 15분 로드 평균 값 읽기
    fscanf(fp, "%lf %lf %lf", &load1, &load5, &load15);
    fclose(fp);  // 파일 닫기

    // 출력
    printf("로드 평균 (1분, 5분, 15분): %.2f, %.2f, %.2f\n", load1, load5, load15);

    return 0;
}
