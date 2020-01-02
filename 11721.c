#include<stdio.h>

int main(){
    char input[100];                //index 0 부터 체우면 마지막 null까지 해서 100 맞음
    scanf("%s", input);            //배열은 그 자체로 주소이므로 &을 붙이지 않아야함.
    
    for(int i = 0; i < strlen(input); i++){    //strlen으로 문자열 길이 알 수 있음.
        printf("%c", input[i]);
        if(i % 10 == 9)    printf("\n"); 
    }
    return 0;
}
