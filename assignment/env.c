#include <stdio.h>
// 환경 변수 출력
extern char **environ;  // 환경 변수에 접근

int main() {
    char **env = environ;

    // 환경 변수 하나씩 출력
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
