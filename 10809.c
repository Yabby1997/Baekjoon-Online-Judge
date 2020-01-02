#include<stdio.h>

int main(){
    char inputString[100] = "";
    char alphabetArray[26] = "abcdefghijklmnopqrstuvwxyz";
    int firstAppearIndex[26] = {0, };
    
    scanf("%s", inputString);
    
    for(int i = 0; i < 26; i++)                                     //INITIALIZE ALL MEMBERS OF ARRAY -1
        firstAppearIndex[i] = -1;
    
    for(int i = 0; i < 26; i++){
        char currentAlphabet = alphabetArray[i];
        for(int j = 0; inputString[j] != '\0'; j++)
            if(firstAppearIndex[i] == -1 && inputString[j] == currentAlphabet)
                firstAppearIndex[i] = j;
    }
    
    for(int i = 0; i < 26; i++)
        printf("%d ", firstAppearIndex[i]);
    
    return 0;
}
