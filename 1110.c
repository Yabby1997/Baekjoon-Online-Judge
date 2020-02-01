#include<stdio.h>

int getCycle(int seedNumber, int currentNumber, int cycle);

int main(){
    int initialNumber;
    
    scanf("%d", &initialNumber);
    if(initialNumber < 0 || initialNumber > 99) return 0;
    else    printf("%d", getCycle(initialNumber, initialNumber, 1));
    return 0;
}

int getCycle(int seedNumber, int currentNumber, int cycle){
    int temp[2];
    int nextNumber;
    temp[1] = currentNumber%10;
    temp[0] = (currentNumber-temp[1])/10;
    nextNumber = (temp[1]*10)+((temp[0]+temp[1])%10);
    if(seedNumber == nextNumber)    return cycle;
    else    return getCycle(seedNumber, nextNumber, cycle+1);
}
