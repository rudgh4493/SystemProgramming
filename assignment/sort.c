#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 입력 줄 정렬
// 최대 100줄, 각 줄 100자까지 저장
char *lines[100];
int count = 0;

// 비교 함수 for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char buffer[100];

    // 표준 입력에서 줄 읽기
    while (fgets(buffer, sizeof(buffer), stdin) && count < 100) {
        lines[count] = strdup(buffer);  // 줄 저장
        count++;
    }

    qsort(lines, count, sizeof(char *), compare);  // 정렬

    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);  // 메모리 해제
    }

    return 0;
}
