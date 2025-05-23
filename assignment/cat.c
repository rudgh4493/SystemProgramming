#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096  // 버퍼 크기
//  파일 내용 출력
int main(int argc, char *argv[]){
    FILE *fp;
    char buf[BUF_SIZE];
    size_t n;

    if(argc < 2) {
         fprintf(stderr, "사용법: %s <파일 이름>\n", argv[0]);
         return 1;
    }

    // 파일 열기
    fp = fopen(argv[1], "r");
    if(fp == NULL){
         perror("파일 열기 오류");
         return 1;
    }

    // 파일 내용 읽고 출력
    while((n = fread(buf, 1, BUF_SIZE, fp)) > 0){
         if(fwrite(buf, 1, n, stdout) != n) {
             perror("출력 오류");
             fclose(fp);
             return 1;
         }
    }

    fclose(fp);
    return 0;
}
