#include<iostream>

using namespace std;

int fibo[41] = {1, 1};

int main(void){
    for(int i = 2; i < 41; i++)
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    int numOfInput;
    cin>>numOfInput;
    for(int i = 0; i < numOfInput; i++){
        int inputNum;
        cin>>inputNum;
        if(inputNum == 0)
            cout<<"1 0"<<endl;
        else if(inputNum == 1)
            cout<<"0 1"<<endl;
        else
            cout<<fibo[inputNum - 2]<<" "<<fibo[inputNum - 1]<<endl;
    }
    return 0;
}
