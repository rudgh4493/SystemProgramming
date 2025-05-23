#include <stdio.h>
#include <stdlib.h>
//  파일 또는 디렉토리 이동 또는 이름 변경
int main(int argc, char *argv[]){
    if(argc < 3){
         fprintf(stderr, "사용법: %s <원본> <대상>\n", argv[0]);
         return 1;
    }

    // 파일/디렉토리 이름 변경 또는 이동
    if(rename(argv[1], argv[2]) != 0){
         perror("이동/이름 변경 오류");
         return 1;
    }

    printf("'%s'를 '%s'로 이동 또는 이름 변경 완료\n", argv[1], argv[2]);
    return 0;
}
