#include<iostream>
#include<vector>

using namespace std;

vector<int> fibo;
int n;

int solveRecursively(int i);

int main(){
	fibo.push_back(0);
	fibo.push_back(1);

	cin >> n;

	cout << solveRecursively(2);
}

int solveRecursively(int i){
	if(n < i)
		return fibo[n];
	fibo.push_back(fibo[i-2] + fibo[i-1]);
	if(i == n)
		return fibo[i];
	return solveRecursively(i+1);
}
