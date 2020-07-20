#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> p;
int result;

int main(){
 	cin >> n;

	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		p.push_back(temp);
	}

	sort(p.begin(), p.end());

	result = p.at(0);
	for(int i = 1; i < n; i++){
		p.at(i) = p.at(i - 1) + p.at(i);
		result += p.at(i);
	}

	cout << result;
}
