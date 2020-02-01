#include<stdio.h>

int calcScore(char givenCase[]);

int main(){
    int testCase = 0;
    scanf("%d", &testCase);
    for(int i = 0; i < testCase; i++){
        char inputCase[80] = "";
        scanf("%s", inputCase);
        printf("%d\n", calcScore(inputCase));
    }
    return 0;
}

int calcScore(char givenCase[]){
    int scoreArray[80] = {0, };
    int totalScore = 0;
    
    if(givenCase[0] == 'O'){                            //CALC FOR FIRST MEMBER OF GIVEN CASE
        scoreArray[0] = 1;
    }
    for(int i = 1; givenCase[i] != '\0'; i++){          //CALC FOR LAST MEMBER OF GIVEN CASE
        if(givenCase[i] == 'O'){
            scoreArray[i] = scoreArray[i-1] + 1;
        }
    }
    for(int i = 0; givenCase[i] != '\0'; i++){          //TOTAL SCORE OF GIVEN CASE
        totalScore = totalScore + scoreArray[i];
    }
    return totalScore;
}
