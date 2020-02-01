#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
	int lengthOfSequence;
    int record = 0;
    vector<int> inputSequence;
    vector<int> sequenceLength;
    vector<int> temp;
    int result = 0;
    
    sequenceLength.push_back(1);
	cin>>lengthOfSequence;
	
	for(int i = 0; i < lengthOfSequence; i++){
        int temp;
        cin>>temp;
        inputSequence.push_back(temp);
	}

    for(int i = 1; i < lengthOfSequence; i++){
        for(int j = 0; j < i; j++){
            if(inputSequence.at(i) > inputSequence.at(j)){
                temp.push_back(sequenceLength.at(j));
            }
            else{
                temp.push_back(0);
            }
        }
        sequenceLength.push_back(*max_element(temp.begin(), temp.end()) + 1);
        temp.clear();
    }
    
    for(int i = 0; i < lengthOfSequence; i++){
        if(result < sequenceLength.at(i))
            result = sequenceLength.at(i);
    }
    
    cout<<result<<endl;
    
	return 0;
}
