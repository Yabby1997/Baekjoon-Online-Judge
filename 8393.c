#include<stdio.h>

int main(){
    int givenNumber = 0, output = 0;
    scanf("%d", &givenNumber);
    
    for(int i = 1; givenNumber >= i; i++)
        output = output + i;
    
    printf("%d", output);
    
    return 0;
}
