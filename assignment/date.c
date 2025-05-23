#include <stdio.h>
#include <time.h>  // 시간 관련 함수
// 날짜/시간 출력
int main() {
    time_t now = time(NULL);  // 현재 시간 획득
    struct tm *t = localtime(&now);  // 지역 시간으로 변환

    // 포맷에 맞게 출력
    printf("현재 시간: %04d-%02d-%02d %02d:%02d:%02d\n",
           t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
           t->tm_hour, t->tm_min, t->tm_sec);

    return 0;
}
