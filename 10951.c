#include<stdio.h>

int main(){
    int A, B;
    
    while(scanf("%d %d", &A, &B) != EOF){        //THIS PROGRAM ENDS WHEN THERE'S NO INPUT
        printf("%d\n", A+B);
    }
    return 0;
}
