#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, k;

void input();
void solve();
int calcSerialLength(int index);

int main(){
    input();
    solve();
    return 0;
}

void solve(){
    if(calcSerialLength(n) < k){
        printf("-1\n");
        return;
    }
    int left = 1;
    int right = n;
    int findingNumber = 0;
    int findingIndex = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        int midLength = calcSerialLength(mid);
        if(midLength < k){
            left = mid + 1;
        }
        else{
            findingNumber = mid;
            findingIndex = midLength - k;
            right = mid - 1;
        }
    }
    string findingNumString = to_string(findingNumber);
    reverse(findingNumString.begin(), findingNumString.end());
    printf("%c\n", findingNumString[findingIndex]);
}

void input(){
    scanf("%d %d", &n, &k);
}

int calcSerialLength(int index){
    int i = 9;
    int temp = index;
    int counter = 1;
    int length = 0;
    while(temp - i > 0){
        temp = temp - i;
        length += i * counter;
        i *= 10;
        counter++;
    }
    length += temp * counter;
    return length;
}

