#include<stdio.h>
#include<iostream>
using namespace std;

int main(void){
    long long fibonacci[91] = {0, 1};                           //-(2^63) ~ 2^63 RANGED DATA TYPE
    int ithValue;
    scanf("%d", &ithValue);
    for(int i = 2; i <= ithValue; i++){
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }
    cout<<fibonacci[ithValue]<<endl;
    return 0;
}
