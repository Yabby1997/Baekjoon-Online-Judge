#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int smaller(int a, int b){
    return ((a <= b) ? a : b);
}

int main(void){
    int inputArray[1000][3];
    int resultArray[1000][3];
    int numOfInput;
    cin>>numOfInput;
    vector<int> temp;
    for(int i = 0; i < numOfInput; i++){
        scanf("%d %d %d", &inputArray[i][0], &inputArray[i][1], &inputArray[i][2]);
    }
    resultArray[0][0] = inputArray[0][0];
    resultArray[0][1] = inputArray[0][1];
    resultArray[0][2] = inputArray[0][2];
    for(int i = 1; i < numOfInput; i++){
        resultArray[i][0] = inputArray[i][0] + smaller(resultArray[i - 1][1], resultArray[i - 1][2]);
        resultArray[i][1] = inputArray[i][1] + smaller(resultArray[i - 1][0], resultArray[i - 1][2]);
        resultArray[i][2] = inputArray[i][2] + smaller(resultArray[i - 1][0], resultArray[i - 1][1]);
    }
    
    printf("%d", smaller(smaller(resultArray[numOfInput - 1][0], resultArray[numOfInput - 1][1]), resultArray[numOfInput - 1][2]));
    return 0;
}
