#include <stdio.h>
//  문자열 출력
int main(int argc, char *argv[]) {
    // argc가 1이면 출력할 문자열이 없으므로 아무것도 출력하지 않음
    if (argc < 2) {
        return 0;
    }

    // argv[1]부터 시작해 인자들을 공백으로 구분해 출력
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" ");  // 단어 사이에 공백 삽입
        }
    }
    printf("\n");  // 출력 후 줄바꿈

    return 0;
}
