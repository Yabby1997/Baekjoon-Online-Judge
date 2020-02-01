#include<stdio.h>

#define SIZE 9

int main(){
    int numArray[SIZE];
    int maxValue = 0;
    int maxIndex = 0;
    
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &numArray[i]);
        if(maxValue < numArray[i]){
            maxValue = numArray[i];
            maxIndex = i;
        }
    }
    printf("%d\n%d", maxValue, maxIndex+1);
    return 0;
}
