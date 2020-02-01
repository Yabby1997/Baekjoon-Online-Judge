#include<iostream>

using namespace std;

int fibo[1000001] = {0, 1, 2};

int fibonacci(int n){
    for(int i = 3; i <= n; i++){
        fibo[i] = fibo[i - 2] + fibo[i - 1];
        fibo[i] = fibo[i] % 15746;
    }
    return fibo[n];
}

int main(void){
    int inputNum;
    cin>>inputNum;
    cout<<fibonacci(inputNum);
    return 0;
}
