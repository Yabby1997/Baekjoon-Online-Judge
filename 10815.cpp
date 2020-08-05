#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> input();
int binarySearch(int value);

vector<int> holdingCards, givenCards;

int main(void){
	holdingCards = input();
	givenCards = input();
	
	sort(holdingCards.begin(), holdingCards.end());
	
	for(int i = 0; i < givenCards.size(); i++)
		printf("%d ", binarySearch(givenCards[i]));

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

int binarySearch(int value){
	int left = 0;
	int right = holdingCards.size();
	int mid;
	while(left <= right){
		mid = (left + right) / 2;
		if(holdingCards[mid] == value)
			return 1;
		else if(holdingCards[mid] > value)
			right = mid - 1;
		else if(holdingCards[mid] < value)
			left = mid + 1;
	}
	return 0;
}
