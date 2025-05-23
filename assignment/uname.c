#include <stdio.h>
#include <sys/utsname.h>  // uname 함수 사용을 위한 헤더
// 시스템 정보 출력
int main() {
    struct utsname sysinfo;

    if (uname(&sysinfo) == -1) {  // 시스템 정보 가져오기
        perror("uname 실패");
        return 1;
    }

    // 다양한 시스템 정보 출력
    printf("시스템 이름: %s\n", sysinfo.sysname);
    printf("노드 이름: %s\n", sysinfo.nodename);
    printf("릴리즈: %s\n", sysinfo.release);
    printf("버전: %s\n", sysinfo.version);
    printf("머신: %s\n", sysinfo.machine);

    return 0;
}
