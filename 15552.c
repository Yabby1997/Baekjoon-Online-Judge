#include<stdio.h>

int main(){
    int iteration = 0;
    scanf("%d", &iteration);
    
    for(int i = 0; i < iteration; i++){
        int A, B;
        scanf("%d %d\n", &A, &B);
        printf("%d\n", A+B);
    }
    return 0;
}
