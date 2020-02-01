#include<stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.9f", (double)a/(double)b);    //.9을 붙여줘서 소숫점 몇번째 자리까지 표현할지 정할 수 있음.
    return 0;
}
