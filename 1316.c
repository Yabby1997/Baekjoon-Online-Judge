#include<stdio.h>

#define NOTASIGNED -99

int recentlyAppeared[26] = {0, };
char alphabetString[] = "abcdefghijklmnopqrstuvwxyz";

void initializeArray();

int main(){
    int numOfWords = 0;
    int nonGroupChar = 0;
    int nonGroupWord = 0;

    scanf("%d", &numOfWords);
    for(int i = 0; i < numOfWords; i++){
        char inputWord[100] = "";
        scanf("%s", inputWord);
        initializeArray();
        
        for(int j = 0; inputWord[j] != '\0'; j++){
            for(int k = 0;  k < 26; k++){
                if(inputWord[j] == alphabetString[k]){
                    if(recentlyAppeared[k] == NOTASIGNED || recentlyAppeared[k] == j-1)
                        recentlyAppeared[k] = j;
                    else{
                        nonGroupChar++;
                    }
                }
            }
        }
        if(nonGroupChar > 0){
            nonGroupWord++;
            nonGroupChar = 0;
        }
    }
    printf("%d", numOfWords-nonGroupWord);
    return 0;
}

void initializeArray(){
    for(int i = 0; i < 26; i++)
        recentlyAppeared[i] = NOTASIGNED;
}
