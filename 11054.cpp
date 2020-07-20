#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> searchBest(vector<int> sequence);

int main(){
	vector<int> sequence;
	int sequenceLength, temp;

	cin>>sequenceLength;
	for(int i = 0; i < sequenceLength; i++){
		cin>>temp;
		sequence.push_back(temp);
	}
	
	vector<int> result = searchBest(sequence);
	reverse(sequence.begin(), sequence.end());
	vector<int> backwardResult = searchBest(sequence);
	reverse(backwardResult.begin(), backwardResult.end());
	
	vector<int> finalResult;

	for(int i = 0; i < result.size(); i++){
		finalResult.push_back(result[i] + backwardResult[i] - 1);	
	}

	cout<<*max_element(finalResult.begin(), finalResult.end())<<endl;

	return 0;
}

vector<int> searchBest(vector<int> sequence){
	vector<int> result;
	result.push_back(1);

	for(int i = 1; i < sequence.size(); i++){
		int currentRecord = 1;
		for(int j = 0; j < i; j++){
			if(sequence[j] < sequence[i]){
				if(currentRecord < result[j] + 1)
					currentRecord = result[j] + 1;
			}
		}
		result.push_back(currentRecord);
	}
	return result;
}
