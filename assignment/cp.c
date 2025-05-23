#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096  // 버퍼 크기
// 파일 또는 디렉토리 복사
int main(int argc, char *argv[]){
    if(argc < 3){
         fprintf(stderr, "사용법: %s <원본 파일> <대상 파일>\n", argv[0]);
         return 1;
    }

    // 원본 파일 열기
    int src = open(argv[1], O_RDONLY);
    if(src < 0) { 
         perror("원본 파일 열기 오류"); 
         return 1; 
    }

    // 대상 파일 열기 (없으면 생성)
    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(dst < 0) { 
         perror("대상 파일 열기 오류"); 
         close(src); 
         return 1;
    }

    char buf[BUF_SIZE];
    ssize_t n;

    // 파일 복사
    while((n = read(src, buf, BUF_SIZE)) > 0){
         if(write(dst, buf, n) != n) {
              perror("쓰기 오류");
              close(src);
              close(dst);
              return 1;
         }
    }

    if(n < 0) { 
         perror("읽기 오류"); 
    }

    close(src);
    close(dst);
    printf("파일 '%s'를 '%s'로 복사함\n", argv[1], argv[2]);
    return 0;
}
