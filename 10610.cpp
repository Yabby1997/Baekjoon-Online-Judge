#include<iostream>
#include<algorithm>

using namespace std;

bool check(string numString);

int main(){
    string inputNum;
    cin>>inputNum;
    
    if(check(inputNum)){
        cout<<inputNum<<endl;
        return 0;
    }
    cout<<"-1"<<endl;
    return 0;
}

bool check(string numString){
    int sum = 0;
    bool zeroIncluded = false;
    for(int i = 0; i < numString.size(); i++){
        if(numString[i] == '0')
            zeroIncluded = true;
        sum += numString[i] - '0';
    }
    return sum % 3 == 0 && zeroIncluded ? true : false;
}

