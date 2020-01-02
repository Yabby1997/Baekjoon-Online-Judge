#include<stdio.h>
#include<stdlib.h>                              //TO USE ATOI FUNCTION

int reverseConverter(char *givenString);

int main(){
    char A[3] = "";
    char B[3] = "";
    scanf("%s %s", &A, &B);
    int reversedA = reverseConverter(A);
    int reversedB = reverseConverter(B);
    if(reversedA - reversedB > 0)
        printf("%d", reversedA);
    else{
        printf("%d", reversedB);
    }
    return 0;
}

int reverseConverter(char *givenString){
    char temp[3] = "";
    for(int i = 0; i < 3; i++)
        temp[2-i] = givenString[i];
    return atoi(temp);                      //ATOI CONVERTS STRING INTO INTEGER
    
}
