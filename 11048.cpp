#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> candy;
int dp[1000][1000];

int solveRecursively(int xPos, int yPos);
int max3(int a, int b, int c);

int main(){
	int n, m;
	cin>>n>>m;

	for(int i = 0; i < n; i++){
		vector<int> temp;
		for(int j = 0; j < m; j++){
			int numOfCandy;
			cin>>numOfCandy;
			temp.push_back(numOfCandy);
			dp[i][j] = -1;
		}
		candy.push_back(temp);
	}
	
	cout<<solveRecursively(n - 1, m - 1)<<endl;

	return 0;
}

int solveRecursively(int xPos, int yPos){
	if(xPos < 0 || yPos < 0)
		return 0;
		
	if(dp[xPos][yPos] == -1)
		dp[xPos][yPos] = max3(solveRecursively(xPos - 1, yPos - 1), solveRecursively(xPos - 1, yPos), solveRecursively(xPos, yPos - 1)) + candy[xPos][yPos];
	
	return dp[xPos][yPos];
}

int max3(int a, int b, int c){
	int maximum = a;
	if(maximum < b)
		maximum = b;
	if(maximum < c)
		maximum = c;
	return maximum;
}
