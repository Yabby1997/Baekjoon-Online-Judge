#include<iostream>
#include<stdio.h>

using namespace std;

int n, totalTails;
char coins[20][20];

void flipRow(int index);
void flipCol(int index);
int target();

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>coins[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<coins[i][j];
		}
		cout<<endl;
	}

	return 0;
}

int target(){
	for(int i = 0;

}
