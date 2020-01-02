#include<stdio.h>

int main(){
    int size, sum = 0;
    char num[100] = {0, };                //초기화
    scanf("%d\n", &size);
    scanf("%s", num);                    //배열의 이름이 곧 주소이다.
    
    for(int i = 0; size > i; i++)        //사이즈는 5라도 인덱스는 0~4임. 5에는 \0이 들어감.
        sum = sum + num[i] - '0';
    
    printf("%d", sum);
    
    return 0;
}
