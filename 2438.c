#include<stdio.h>

int main(){
    int input;
    scanf("%d", &input);
 
    for(int j = 0; j < input; j++){
        for(int i = 0; i <= j; i++)
            printf("*");
        printf("\n");
    }
}
