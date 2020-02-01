#include<stdio.h>
#include<math.h>                                                                //TO USE POWER CALCULATION, YOU NEED TO INCLUDE MATH.H TO USE PWE FUNC WHICH RETURNS DOUBLE DATA

void solveHanoiRecursively(int inputNum, int from, int by, int dest);

int main(){
    int inputNum = 0;
    scanf("%d", &inputNum);
    printf("%d\n", (int)pow(2, inputNum) - 1);                                  //ITERATION IS CALCULATED BY THIS EQUATION
    solveHanoiRecursively(inputNum, 1, 2, 3);
    return 0;
}

void solveHanoiRecursively(int inputNum, int from, int by, int dest){           
    if(inputNum == 1){                                                          //IF CURRENT ONE IS SMALLEST ONE, YOU NEED TO MOVE ANOTHER WAY
        printf("%d %d\n", from, dest);
    }
    else{                                       
        solveHanoiRecursively(inputNum - 1, from, dest, by);                    //TO MOVE BIGGEST ONE, YOU SHOULD MOVE SMALLER ONES TO ANOTHER POLE
        printf("%d %d\n", from, dest);                                          //IF YOU MOVE ALL THOSE SMALLER ONES, NOW YOU CAN MOVE BIGGEST ONE TO THE DESTINATION POLE
        solveHanoiRecursively(inputNum - 1, by, from, dest);                    //ONCE YOU MOVE YOUR BIGGEST ONE, YOU NOW NEED TO MOVE SMALLER ONES ABOVE BIGGEST ONE YOU JUST MOVED
    }
}
