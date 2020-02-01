#include<iostream>
#include<vector>

using namespace std;

int biggerOne(int A, int B){
    return ((A >= B) ? A : B);
}

int main(void){
	int numOfSteps;
    int steps[301] = {0};
    int bestScore[301] = {0};
	cin>>numOfSteps;
	for(int i = 1; i <= numOfSteps; i++){
		int	stepScore;
		cin>>stepScore;
		steps[i] = stepScore;
	}
		bestScore[1] = steps[1];
		bestScore[2] = steps[1] + steps[2];
		bestScore[3] = biggerOne(steps[1] + steps[3], steps[2] + steps[3]);
		
	for(int i = 4; i <= numOfSteps; i++)
		bestScore[i] = biggerOne(bestScore[i - 2] + steps[i], bestScore[i - 3] + steps[i - 1] + steps[i]);
		
	cout<<bestScore[numOfSteps]<<endl;
	return 0;
}



