#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> glass = {0};
vector<int> best = {0};

int biggerOne(int A, int B){
    return ((A >= B) ? A : B);
}

int main(void){
    int numOfInput;
    int capacityOfGlass;
    cin>>numOfInput;
    for(int i = 0; i < numOfInput; i++){
        cin>>capacityOfGlass;
        glass.push_back(capacityOfGlass);
    }
    best.push_back(glass[1]);
    best.push_back(glass[1] + glass[2]);
    
    for(int i = 3; i <= glass.size(); i++){
        int currentBest = biggerOne(best[i - 1], biggerOne((best[i - 2] + glass[i]), (best[i - 3] + glass[i - 1] + glass[i])));
        best.push_back(currentBest);
    }
    cout<<best.back()<<endl;
    return 0;
}
