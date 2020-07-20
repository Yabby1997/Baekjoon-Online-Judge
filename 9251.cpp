#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[1001][1001] = {0, };

int main(){
    string first, second;
    int maxLength = 0;
    cin>>first;
    cin>>second;
    
    for(int i = 1; i <= first.size(); i++){
        for(int j = 1; j <= second.size(); j++){
            dp[i][j] = second[j - 1] == first[i - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
            if(maxLength < dp[i][j])
                maxLength = dp[i][j];
        }
    }
    cout<<maxLength<<endl;
}

