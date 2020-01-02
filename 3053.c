#include<stdio.h>

int main(){
    int inputNum;
    scanf("%d", &inputNum);
    printf("%6lf\n%6lf", inputNum * inputNum * 3.1415926535897932384626, inputNum * inputNum * 2.0);
    return 0;
}
