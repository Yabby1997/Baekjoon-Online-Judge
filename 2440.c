#include<stdio.h>

int main(){
    int input = 0;
    scanf("%d", &input);
    
    for(input; input > 0; input--){
        for(int i = 1; input >= i; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}
