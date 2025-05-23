#include <stdio.h>
// 문자열 무한 반복 출력
int main(int argc, char *argv[]) {
    const char *text = (argc > 1) ? argv[1] : "y";  // 인자가 없으면 기본은 "y"

    // 무한 루프를 돌며 문자열 반복 출력
    while (1) {
        printf("%s\n", text);  // 줄마다 출력
    }

    return 0;
}
