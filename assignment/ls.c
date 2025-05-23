#include <stdio.h>
#include <dirent.h>
//  디렉토리 목록 출력
int main() {
    DIR *dir;                  // 디렉토리를 가리키는 포인터
    struct dirent *entry;     // 디렉토리 항목 구조체 포인터

    dir = opendir(".");       // 현재 디렉토리 열기
    if (dir == NULL) {
        perror("opendir 오류");  // 열기 실패 시 오류 출력
        return 1;
    }

    // 디렉토리 내 항목을 하나씩 읽어서 출력
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);  // 파일/디렉토리 이름 출력
    }

    closedir(dir);  // 디렉토리 닫기
    return 0;
}
