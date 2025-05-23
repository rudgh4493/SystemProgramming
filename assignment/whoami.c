#include <stdio.h>        // 입출력
#include <unistd.h>       // getuid 함수
#include <pwd.h>          // passwd 구조체 및 getpwuid 함수
//  현재 사용자 출력
int main() {
    uid_t uid = getuid();             // 현재 사용자 UID 가져오기
    struct passwd *pw = getpwuid(uid);  // UID로 사용자 정보 얻기

    if (pw) {
        printf("%s\n", pw->pw_name);  // 사용자 이름 출력
    } else {
        perror("사용자 이름 확인 실패");
    }

    return 0;
}
