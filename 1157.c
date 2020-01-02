#include<stdio.h>

int main(){
    int alphabetIndex[26] = {0, };
    char alphabetArray[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    char inputString[1000000] = "";
    int mostAppearedIndex = 0;
    scanf("%s", inputString);
    
    for(int i = 0; inputString[i] != '\0'; i++){
        for(int j = 0; j < 26; j++){
            if(inputString[i] == alphabetArray[j] || inputString[i] == alphabetArray[j]+32){        //SMALL CHAR + 32 = BIG CHAR
                alphabetIndex[j]++;
            }
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(alphabetIndex[i] > alphabetIndex[mostAppearedIndex]){
            mostAppearedIndex = i;
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(i != mostAppearedIndex && alphabetIndex[i] == alphabetIndex[mostAppearedIndex])
            mostAppearedIndex = 26;
    }
    
    printf("%c", alphabetArray[mostAppearedIndex]);
    return 0;
}
