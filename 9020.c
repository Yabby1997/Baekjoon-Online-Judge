#include<stdio.h>

int main(){
    int primeNumber[10001] = {0, };                             //0 = PRIME, 1 != PRIME
    primeNumber[0] = 1;
    primeNumber[1] = 1;
    for(int i = 2; i < 10001; i++){
        for(int j = 2; j <= sqrt(10001); j++){
            if(i * j > 10001)
                break;
            else
                primeNumber[i * j] = 1;
        }
    }
    int numOfCases;
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        int inputNum;
        scanf("%d", &inputNum);
        for(int j = inputNum/2; j > 1; j--){
            if(primeNumber[j] == 0 && primeNumber[inputNum - j] == 0){
                printf("%d %d\n", j, inputNum - j);
                break;
            }
        }
    }
    return 0;
}
