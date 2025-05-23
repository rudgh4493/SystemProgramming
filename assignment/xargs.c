#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 입력을 명령 인자로 전달
// 간단한 xargs 흉내: 입력을 받아서 인자로 명령어 실행
int main() {
    char input[1024];
    printf("입력 (공백 구분): ");
    fgets(input, sizeof(input), stdin);  // 표준 입력 받기
    input[strcspn(input, "\n")] = 0;     // 개행 문자 제거

    char cmd[1050];
    snprintf(cmd, sizeof(cmd), "echo %s", input);  // 간단히 echo로 출력
    system(cmd);  // 실행

    return 0;
}
