#include<stdio.h>

int main(){
    int primeNumbers[1000001] = {0, };                          // 1 = NOTPRIME 0 = PRIME
    
    for(int i = 2; i < 1000001; i++){
        for(int j = 2; j <= sqrt(1000001); j++){
        if(i * j > 1000001)
            break;
        else
            primeNumbers[i * j] = 1;
        }
    }
    primeNumbers[0] = 1;
    primeNumbers[1] = 1;
    
    int from, to;
    scanf("%d %d", &from, &to);
    
    for(int i = from; i <= to; i++){
        if(primeNumbers[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}
