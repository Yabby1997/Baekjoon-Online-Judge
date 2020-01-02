#include<stdio.h>

int main(){
    char input[101];
    
    while(fgets(input, 101, stdin)){
        printf(input);
    }
    return 0;
}
