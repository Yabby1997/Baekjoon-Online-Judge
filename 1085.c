#include<stdio.h>

int main(){
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int minimum = x;
    w = w - x;
    h = h - y;
    int inputNums[] = {x, y, w, h};
    
    for(int i = 0; i < 4; i++){
        if(minimum > inputNums[i]){
            minimum = inputNums[i];
        }
    }
    printf("%d", minimum);
    return 0;
}
