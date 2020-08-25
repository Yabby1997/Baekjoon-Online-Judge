#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int numbers[10001] = {0, };

int numOfInput;

void input();
void show();

int main(){
    input();
    show();
    return 0;
}

void input(){
    scanf("%d", &numOfInput);
    for(int i = 0; i < numOfInput; i++){
        int temp;
        scanf("%d", &temp);
        numbers[temp]++;
    }
}

void show(){
    for(int i = 0; i < 10001; i++){
        if(numbers[i] == 0)
            continue;
        for(int j = 0; j < numbers[i]; j++){
            printf("%d\n", i);
        }
    }
}

