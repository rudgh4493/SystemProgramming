#include<stdio.h>
int main(){
    int num;
    char name[100];
    printf("학번를 입력하세요: ");
    scanf("%d", &num); 
    printf("\n");
    printf("이름를 입력하세요: ");
    scanf("%s", name); 

    printf("학번: %d, 이름: %s\n", num, name);

    return 0;
}