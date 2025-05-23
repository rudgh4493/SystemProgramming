#include <stdio.h>        // 입출력
#include <unistd.h>       // UID, GID 함수
#include <sys/types.h>    // 타입 정의
#include <grp.h>          // 그룹 정보
#include <pwd.h>          // 사용자 정보
// 사용자와 그룹 정보 출력
int main() {
    uid_t uid = getuid();             // 현재 사용자 UID
    gid_t gid = getgid();             // 현재 그룹 GID

    struct passwd *pw = getpwuid(uid);  // UID로 사용자 정보
    struct group *gr = getgrgid(gid);   // GID로 그룹 정보

    if (pw && gr) {
        printf("uid=%d(%s) gid=%d(%s)\n",
               uid, pw->pw_name,     // UID와 사용자 이름
               gid, gr->gr_name);    // GID와 그룹 이름
    } else {
        perror("사용자/그룹 정보 가져오기 실패");
    }

    return 0;
}
