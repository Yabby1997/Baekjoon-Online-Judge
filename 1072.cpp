#include<stdio.h>

using namespace std;

int calcWinningRatio(int wins, int games);

int main(){
	int games, wins, initialWinningRatio, targetWinningRatio;
	scanf("%d %d", &games, &wins);
	
	if(games == wins){
		printf("-1\n");
		return 0;
	}

	initialWinningRatio = calcWinningRatio(wins, games);
	int i = 1;
	while(calcWinningRatio(wins + i, games + i) != initialWinningRatio + 1){
		i ++;
	}
	printf("%d\n", i);
	return 0;
}

int calcWinningRatio(int wins, int games){
	return (int)((float)wins/(float)games * 100);
}
