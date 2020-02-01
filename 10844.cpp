#include<iostream>

using namespace std;

int dp[102][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main(void){
    int inputNum;
    int result = 0;
    
    cin>>inputNum;
    
    for(int i = 2; i <= inputNum; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for(int j = 1; j < 9; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    
    for(int i = 0; i <= 9; i++){
        result = (result + dp[inputNum][i]) % 1000000000;
    }
    
    cout<<result<<endl;
    return 0;
}
