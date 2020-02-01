#include<iostream>

using namespace std;

long long padovan[102] = {0, 1, 1, 1, 2, 2, 3, 4, 5};

long long solvePadovan(int n){
    if(n == 0)
        return 0;
    if(padovan[n] != 0)
        return padovan[n];
    else{
        padovan[n] = solvePadovan(n - 1) + solvePadovan(n - 5);
        return padovan[n];   
    }
}

int main(void){
    int numOfInput;
    for(int i = 9; i < 102; i++)
        padovan[i] = 0;
    cin>>numOfInput;
    for(int i = 0; i < numOfInput; i++){
        int inputNum;
        cin>>inputNum;
        cout<<solvePadovan(inputNum)<<endl;
    }
    return 0;
}
