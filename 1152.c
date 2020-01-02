#include<stdio.h>

int main(){
    char inputString[1000000] = "";     //all members of array is \0
    int stringSize = 0;
    int wordCounter = 1;
    
    scanf("%[^\n]", inputString);       //%[^"something"]   scan until "something" came out
    stringSize = sizeof(inputString)/sizeof(inputString[0]);
    for(int i = 0; i < stringSize; i++) if(inputString[i] == ' ' && inputString[i+1] != '\0')   wordCounter++;
    if(inputString[0] == ' ')   wordCounter--;
    printf("%d", wordCounter);
    return 0;
}
