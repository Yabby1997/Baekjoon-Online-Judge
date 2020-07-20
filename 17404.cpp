#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int numberOfHouses;
int costOfColorsOfHouses[1000][3];
int dp[1000][3];

int getResultWithInitColor(int color);
void dpClear();

int main(void){
    cin>>numberOfHouses;
    for(int i = 0; i < numberOfHouses; i++){
        scanf("%d %d %d", &costOfColorsOfHouses[i][0], &costOfColorsOfHouses[i][1], &costOfColorsOfHouses[i][2]);
    }
    
    int initWithR = getResultWithInitColor(0);
    int initWithG = getResultWithInitColor(1);
    int initWithB = getResultWithInitColor(2);
    
    cout<<min(min(initWithR, initWithG), initWithB)<<endl;
    
    return 0;
}

int getResultWithInitColor(int color){
    dpClear();
    dp[0][color] = costOfColorsOfHouses[0][color];
    int temp = costOfColorsOfHouses[numberOfHouses - 1][color];
    costOfColorsOfHouses[numberOfHouses - 1][color] = 100000000;
    
    for(int i = 1; i < numberOfHouses; i++){
        dp[i][0] = costOfColorsOfHouses[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costOfColorsOfHouses[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costOfColorsOfHouses[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
    }
    costOfColorsOfHouses[numberOfHouses - 1][color] = temp;
    return min(min(dp[numberOfHouses - 1][0], dp[numberOfHouses - 1][1]), dp[numberOfHouses - 1][2]);
}

void dpClear(){
    dp[0][0] = 100000000;
    dp[0][1] = 100000000;
    dp[0][2] = 100000000;
    for(int i = 1; i < numberOfHouses; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
    }
}

