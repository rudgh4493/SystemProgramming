#include <stdio.h>
#include <unistd.h>
#include <limits.h>
//  현재 작업 디렉토리 경로 출력
int main() {
    char cwd[PATH_MAX];  // 현재 디렉토리 경로 저장용 버퍼

    // 현재 작업 디렉토리를 얻어오기
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);  // 성공 시 경로 출력
    } else {
        perror("getcwd 오류");  // 실패 시 오류 출력
        return 1;
    }

    return 0;
}
