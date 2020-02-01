#include<stdio.h>

float averageOfScores(int *array, int sizeOfArray);
float percentageAboveAverage(int *array, int sizeOfArray, float averageScore);

int main(){
    int numOfCases;
    int numOfSubjects;
    
    scanf("%d\n", &numOfCases);
    
    for(int i = 0; i < numOfCases; i++){
        scanf("%d\n", &numOfSubjects);
        int scoreArray[numOfSubjects];
        
        float averageScore = 0;
        float result = 0;
        
        for(int j = 0; j < numOfSubjects; j++){
            scanf("%d", &scoreArray[j]);    
        }    
        
        //size를 변수로 주고 해결
        averageScore = averageOfScores(scoreArray, sizeof(scoreArray)/sizeof(int));
        result = percentageAboveAverage(scoreArray, sizeof(scoreArray)/sizeof(int), averageScore);
        
        printf("%.3f%%\n", result);
    }
    return 0;
}
        //함수내에서 size를 해결하려하면 size가 2로 고정되는 문제가 생김. 이유는 모르겠다.
float averageOfScores(int *array, int sizeOfArray){
    int sum = 0;
    for(int i = 0; i < sizeOfArray; i++)    sum = sum + array[i];
    return (float)sum/sizeOfArray;
        //형변환은 한번씩만 해줘도 될듯.
}

float percentageAboveAverage(int array[], int sizeOfArray, float averageScore){
    int averageAboveCounter = 0;
    for(int i = 0; i < sizeOfArray; i++)    if((float)array[i] > averageScore)    averageAboveCounter++;
    return (float)(averageAboveCounter*100)/sizeOfArray;
}
