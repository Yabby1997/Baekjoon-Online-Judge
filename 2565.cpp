#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> lines;

int main(){
	int numOfLines;
	int biggestNumber = 0;
	vector<int> dp = {1};
	cin>>numOfLines;

	for(int i = 0; i < numOfLines; i++){
		int a, b;
		vector<int> temp;
		cin>>a>>b;
		temp.push_back(a);
		temp.push_back(b);
		lines.push_back(temp);
	}

	sort(lines.begin(), lines.end(), [](const vector<int>& a, const vector<int>& b) {
  		return a[0] < b[0];
	});
	
	for(int i = 1; i < numOfLines; i++){
		int best = 0;
		for(int j = 0; j < i; j++){
			if(lines[i][1] > lines[j][1]){
				if(best < dp[j])
					best = dp[j];
			}
		}
		dp.push_back(best + 1);
	}
	
	cout<<numOfLines - *max_element(dp.begin(), dp.end())<<endl;
}
