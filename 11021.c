#include<stdio.h>

int main(){
    int numOfCases;
    scanf("%d", &numOfCases);
    
    for(int i = 0; i < numOfCases; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i+1, A+B);
    }
    return 0;
}
