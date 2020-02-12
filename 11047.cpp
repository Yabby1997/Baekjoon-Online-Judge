#include<iostream>
#include<list>

using namespace std;

int main(void){
	int numberOfValues;
	int targetValue;
	int best = 0;
	list<int> coinValue;

	cin>>numberOfValues;
	cin>>targetValue;

	for(int i = 0; i < numberOfValues; i++){
		int tempValue = 0;
		cin>>tempValue;
		coinValue.push_front(tempValue);
	}

	for(list<int>::iterator i = coinValue.begin(); i != coinValue.end(); ++i){
		int currentCoin = targetValue / *i;
		if(currentCoin > 0){
			best += currentCoin;
			targetValue -= ((*i) * currentCoin);
		}
	}

	if(targetValue == 0){
		cout<<best<<endl;
	}
	else{
		cout<<"error occured!"<<endl;
	}

	return 0;
}
