#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
//  소유자 변경
int main(int argc, char *argv[]) {
    uid_t uid;
    char *filename;

    // 사용법: chown uid 파일명
    if (argc != 3) {
        fprintf(stderr, "사용법: %s uid 파일명\n", argv[0]);
        return 1;
    }

    uid = (uid_t)atoi(argv[1]);
    filename = argv[2];

    // 소유자 변경: 그룹은 현재 값 유지 (-1)
    if (chown(filename, uid, (gid_t)-1) == -1) {
        perror("chown 실패");
        return 1;
    }

    printf("파일 '%s' 소유자가 UID %d 로 변경되었습니다.\n", filename, uid);
    return 0;
}
