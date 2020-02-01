#include<stdio.h>

int main(){
    int from, to;
    int minimum = 0;
    int sum = 0;
    scanf("%d\n%d", &from, &to);
    for(int i = from; i <= to; i++){
        int j = 2;
        while(1){
            if(i == 1)
                break;
            else if(i == j){
                if(minimum == 0)
                    minimum = i;
                sum = sum + i;
            }
            else if(i % j == 0)
                break;
            else if(j > i)
                break;
            j++;
        }
    }
    if(minimum == 0){
        printf("-1");
    }
    else{
        printf("%d\n%d", sum, minimum);
    }
    return 0;
}
