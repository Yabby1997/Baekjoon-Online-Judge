#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n, k;

	cin >> n >> k;
	
	int results[k + 1] = {0, };

	for(int i = 0; i < n; i++){
		int tempW, tempV;
		cin >> tempW >> tempV;
		results[tempW] = tempV;
	}

	for(int i = 1; i < k + 1; i++){
		if(results[i] == 0)
			continue;
		for(int j = i + 1; j < k + 1; j++){
			if(i + j <= k){
				int newResult = results[i] + results[j];
				if(results[i + j] < newResult)
					results[i + j] = newResult;
			}
		}
	}
	cout << results[k];
}

