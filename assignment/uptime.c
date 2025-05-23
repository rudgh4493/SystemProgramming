#include <stdio.h>
#include <sys/sysinfo.h>  // sysinfo 구조체를 사용하기 위한 헤더
// 시스템 부팅 이후 경과 시간 출력
int main() {
    struct sysinfo info;

    // 시스템 정보를 가져옴 (uptime 포함)
    if (sysinfo(&info) == -1) {
        perror("sysinfo 실패");
        return 1;
    }

    // uptime은 초 단위이므로 시, 분, 초로 변환
    int hours = info.uptime / 3600;
    int minutes = (info.uptime % 3600) / 60;
    int seconds = info.uptime % 60;

    // 경과 시간을 포맷에 맞춰 출력
    printf("시스템 부팅 이후 경과 시간: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
