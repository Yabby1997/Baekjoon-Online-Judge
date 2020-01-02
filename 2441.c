#include<stdio.h>

int main(){
    int input;
    scanf("%d", &input);
    
    for(int i = input; i > 0; --i){
        for(int j = 1; input - i >= j; ++j)
            printf(" ");
        for(int j = 1; i >= j; ++j)
            printf("*");
        printf("\n");
    }
}
