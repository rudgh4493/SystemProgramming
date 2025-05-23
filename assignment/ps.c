#include <stdio.h>            // 표준 입출력
#include <dirent.h>           // 디렉토리 탐색용
#include <ctype.h>            // 숫자인지 확인하기 위한 isdigit()
//  프로세스 목록 보기
int main() {
    DIR *proc = opendir("/proc");   // /proc 디렉토리 열기
    struct dirent *entry;           // 디렉토리 항목 저장용

    if (!proc) {
        perror("/proc 열기 실패");  // 열기 실패 시 오류 출력
        return 1;
    }

    printf("PID\tCMD\n");  // 헤더 출력

    // /proc 내 항목 반복 탐색
    while ((entry = readdir(proc)) != NULL) {
        // 이름이 숫자인 디렉토리만 (프로세스 디렉토리)
        if (isdigit(entry->d_name[0])) {
            char path[256], cmdline[256];  // 파일 경로와 명령어 버퍼
            FILE *f;

            // /proc/<pid>/comm 파일에 명령어 이름이 있음
            snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
            f = fopen(path, "r");

            if (f) {
                if (fgets(cmdline, sizeof(cmdline), f)) {
                    printf("%s\t%s", entry->d_name, cmdline);  // PID와 명령어 출력
                }
                fclose(f);  // 파일 닫기
            }
        }
    }

    closedir(proc);  // 디렉토리 닫기
    return 0;
}
