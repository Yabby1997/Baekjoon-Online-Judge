#include<stdio.h>

int apartment[15][15] = {0, };

void initialize();
void calculate();

int main(){
    initialize();
    calculate();
    int numOfCases;
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        int flr, rm;
        scanf("%d", &flr);
        scanf("%d", &rm);
        printf("%d\n", apartment[flr][rm]);
    }
    return 0;
}

void initialize(){
    for(int i = 1; i < 15; i++){
        apartment[0][i] = i;
    }
    for(int i = 1; i < 15; i++){
        apartment[i][0] = 0;
    }
}

void calculate(){
    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
        }
    }
}
