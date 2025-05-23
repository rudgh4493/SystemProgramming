#include <stdio.h>
#include <stdlib.h>
//  파일 또는 디렉토리 삭제
int main(int argc, char *argv[]){
    if(argc < 2) {
        fprintf(stderr, "사용법: %s <파일 이름>\n", argv[0]);
        return 1;
    }

    // 파일 삭제
    if(remove(argv[1]) != 0) {
        perror("파일 삭제 오류");
        return 1;
    }

    printf("파일 '%s' 삭제됨\n", argv[1]);
    return 0;
}
