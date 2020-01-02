#include<stdio.h>

int main(){
    int numOfCase = 0;
    int charIteration = 0;
    char inputString[20] = "";
    
    scanf("%d", &numOfCase);
    for(int i = 0; i < numOfCase; i++){
        scanf("%d %s", &charIteration, inputString);
        for(int j = 0; inputString[j] != '\0'; j++)
            for(int k = 0; k < charIteration; k++)
                printf("%c", inputString[j]);
        printf("\n");
    }
    return 0;
}
