#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define PAGE_LINES 20
//  more보다 향상된 페이지 뷰어
// 터미널 설정을 원래 상태로 복원할 함수
void reset_terminal_mode(struct termios *orig_termios) {
    tcsetattr(STDIN_FILENO, TCSANOW, orig_termios);
}

// 터미널을 raw 모드로 설정하는 함수
void set_raw_mode(struct termios *orig_termios) {
    struct termios raw;

    tcgetattr(STDIN_FILENO, orig_termios);
    raw = *orig_termios;

    raw.c_lflag &= ~(ICANON | ECHO); // 캐논 모드, 에코 끄기
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    char buffer[1024];
    int line_count = 0;
    struct termios orig_termios;
    int c;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일명\n", argv[0]);
        return 1;
    }
    filename = argv[1];

    fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 오류");
        return 1;
    }

    set_raw_mode(&orig_termios);  // 터미널 raw 모드 설정

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fputs(buffer, stdout);
        line_count++;

        if (line_count == PAGE_LINES) {
            printf("\n-- 스페이스(다음 페이지), q(종료) --\n");
            c = getchar();

            if (c == 'q') {  // q 누르면 종료
                break;
            } else if (c == ' ') {  // 스페이스 누르면 계속 출력
                line_count = 0;
            } else {
                // 그 외 키는 무시
            }
        }
    }

    reset_terminal_mode(&orig_termios);  // 원래 터미널 모드 복원
    fclose(fp);
    return 0;
}
