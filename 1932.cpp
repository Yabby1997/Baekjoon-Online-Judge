#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    vector<int> prevVector;
    int numOfInput;
    cin>>numOfInput;
    for(int i = 0; i < numOfInput; i++){
        int temp;
        vector<int> currentVector = {};
        for(int j = 0; j <= i; j++){
            cin>>temp;
            currentVector.push_back(temp);
        }
        if(i != 0){
            currentVector[0] += prevVector[0];
            currentVector[currentVector.size() - 1] += prevVector[currentVector.size() - 2];
            for(int j = 1; j < currentVector.size() - 1; j++){
                currentVector[j] += ((prevVector[j] >= prevVector[j - 1]) ? prevVector[j] : prevVector[j - 1]);
            }
        }
        prevVector = currentVector;
    }
    cout<<*max_element(prevVector.begin(), prevVector.end())<<endl;
    return 0;
}
