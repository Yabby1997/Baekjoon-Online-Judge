#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> input();
vector<int> givenNumbers, searchingNumbers;
int binarySearch(int val);

int main(){
	givenNumbers = input();
	searchingNumbers = input();
	
	sort(givenNumbers.begin(), givenNumbers.end());

	for(int i = 0; i < searchingNumbers.size(); i++){
		printf("%d\n", binarySearch(searchingNumbers[i]));
	}

	return 0;
}

vector<int> input(){
	vector<int> temp;
	int numOfInput;
	scanf("%d", &numOfInput);

	for(int i = 0; i < numOfInput; i++){
		int input;
		scanf("%d", &input);
		temp.push_back(input);
	}
	return temp;
}

int binarySearch(int val){
	int left = 0;
	int right = givenNumbers.size();

	while(left <= right){
		int mid = (right + left) / 2;
		if(givenNumbers[mid] == val)
			return 1;
		else if(givenNumbers[mid] > val)
			right = mid - 1;
		else if(givenNumbers[mid] < val)
			left = mid + 1;
	}
	return 0;
}
