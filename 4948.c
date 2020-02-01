#include<stdio.h>

int main(){
    int primeNumbers[246913] = {0, };                          // 1 = NOTPRIME 0 = PRIME
    
    for(int i = 2; i < 246913; i++){
        for(int j = 2; j <= sqrt(246913); j++){
        if(i * j > 246913)
            break;
        else
            primeNumbers[i * j] = 1;
        }
    }
    primeNumbers[0] = 1;
    primeNumbers[1] = 1;
    
    int inputNum = 1;
    int counter = 0;
    
    while(inputNum != 0){
        scanf("%d", &inputNum);
        if(inputNum == 0)
            break;
        else{
            for(int i = inputNum + 1; i < inputNum * 2 + 1; i++){
                if(primeNumbers[i] == 0)
                counter++;
            }
            printf("%d\n", counter);
            counter = 0;
        }
    }
    return 0;
}
