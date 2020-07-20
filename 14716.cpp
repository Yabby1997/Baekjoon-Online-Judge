#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int r, c;
int group = 2;
vector<vector<int>> img;


void neighborCheck(int i, int j, int group){
	if(i < 0 || j < 0 || i > r || j > c || img[i][j] != 1)
		return;
	else{
		img[i][j] = group;
		neighborCheck(i-1, j-1, group);
		neighborCheck(i-1, j, group);
		neighborCheck(i-1, j+1, group);
		neighborCheck(i, j-1, group);
		neighborCheck(i, j+1, group);
		neighborCheck(i+1, j-1, group);
		neighborCheck(i+1, j, group);
		neighborCheck(i+1, j+1, group);
	}	
}


int main(){
	cin >> r >> c;

	for(int i = 0;  i < r; i++){
		vector<int> tempVector;
		for(int j = 0; j < c; j++){
			int temp;
			cin >> temp;
			tempVector.push_back(temp);
		}
		img.push_back(tempVector);
	}


	for(int i = 0;  i < r; i++){
		for(int j = 0; j < c; j++){
			if(img[i][j] == 1){
				neighborCheck(i, j, group);
				group++;
			}
		}
	}

	//for(int i = 0;  i < r; i++){
	//	for(int j = 0; j < c; j++){
	//		 cout << img.at(i).at(j);
	//	}
	//	cout<<endl;
	//}

	cout << group - 2;
}
