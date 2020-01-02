#include<stdio.h>

int factorial(int inputNum);

int main(){
    int seedNum = 0;
    scanf("%d", &seedNum);
    printf("%d", factorial(seedNum));
    return 0;
}

int factorial(int inputNum){
    int result = 1;
    for(int i = inputNum; i > 0; i--){
        result = result * i;
    }
    return result;
}
