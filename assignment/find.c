#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>  // 디렉토리 관련 함수
#include <sys/stat.h>
#include <unistd.h>
//  파일 또는 디렉토리 검색
void find_in_dir(const char *dir_path, const char *target_name) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("디렉토리 열기 실패");
        return;
    }

    struct dirent *entry;
    char path[1024];

    while ((entry = readdir(dir)) != NULL) {
        // "."과 ".."은 무시
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 검색할 전체 경로 생성
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        // 이름이 target_name과 일치하면 출력
        if (strcmp(entry->d_name, target_name) == 0) {
            printf("%s\n", path);
        }

        // 디렉토리이면 재귀 탐색
        struct stat st;
        if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
            find_in_dir(path, target_name);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // 인자가 2개여야 함: 프로그램명, 검색할 파일/디렉토리 이름
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 검색할_이름\n", argv[0]);
        return 1;
    }

    // 현재 디렉토리(.)부터 검색 시작
    find_in_dir(".", argv[1]);
    return 0;
}
