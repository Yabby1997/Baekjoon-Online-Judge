#include<stdio.h>

int main(){
    int numOfInput;
    int maxScore; 
    double editedTotal = 0;
    
    scanf("%d", &numOfInput);
    int scoreArray[numOfInput];
    
    for(int i = 0; i < numOfInput; i++){
        scanf("%d", &scoreArray[i]);    
    }
    
    for(int ithMaximum = 0; ithMaximum < numOfInput; ithMaximum++){
        for(int current = 0; current < numOfInput-1-ithMaximum; current++){
            if(scoreArray[current] > scoreArray[current+1]){
                int temp = scoreArray[current];
                scoreArray[current] = scoreArray[current+1];
                scoreArray[current+1] = temp;
            }
        }    
    }
    
    maxScore = scoreArray[numOfInput-1];
    
    for(int i = 0; i < numOfInput; i++){
        editedTotal = editedTotal + scoreArray[i];
    }
    
    double result = (editedTotal*100)/(maxScore*numOfInput);
    printf("%f", result);
        
    return 0;
}
