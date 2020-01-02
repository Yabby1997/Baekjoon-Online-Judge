#include<stdio.h>
#include<math.h>

int square(int input);

int main(){
    int numOfCases;
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        int x1, y1, r1, x2, y2, r2;
        int result = 0;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int distance = square(x2 - x1) + square(y2 - y1);
        if(distance == 0 && r2 == r1){
            if(r1 == 0)
                result = 1;
            else
                result = -1;
        }
        else if(square(r1 + r2) == distance || square(r2 - r1) == distance)
            result = 1;
        else if(square(r1 + r2) < distance || square(r2 - r1) > distance)
            result = 0;
        else if(square(r1 + r2) > distance)
            result = 2;
        printf("%d\n", result);
    }
    return 0;
}

int square(int input){
    return input * input;
}
