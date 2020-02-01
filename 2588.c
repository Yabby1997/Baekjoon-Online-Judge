#include<stdio.h>

int main(){
    int numA = 0;
    int numB = 0;
    
    scanf("%d", &numA);
    scanf("%d", &numB);
    
    int A = numB/100;
    int B = (numB - A * 100)/10;
    int C = (numB - A * 100 - B * 10);       
    
    printf("%d\n%d\n%d\n%d", numA * C, numA * B, numA * A, numA * numB);
    
    return 0;
}
