#include<stdio.h>

int main(){
    int lengthOfInput, X;
    scanf("%d %d", &lengthOfInput, &X);
    
    for(int i = 0; i < lengthOfInput; i++){
        int currentInput;
        scanf("%d", &currentInput);
        if(currentInput < X)
            printf("%d ", currentInput);
    }
    return 0;
}
