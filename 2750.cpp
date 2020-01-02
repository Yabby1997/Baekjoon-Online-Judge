#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
    int numOfInput;
    int inputNums[1000000];
    scanf("%d", &numOfInput);
    for(int i = 0; i < numOfInput; i++){
        scanf("%d", &inputNums[i]);
    }
    sort(inputNums, inputNums + numOfInput);
    
    for(int i = 0; i < numOfInput; i++){
        printf("%d\n", inputNums[i]);
    }
    return 0;
}
