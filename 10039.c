#include<stdio.h>

int main(){
    int guys[5];
    int total = 0;
    int average = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &guys[i]);
    }
    for(int i = 0; i < 5; i++){
        if(guys[i] < 40){
            total = total + 40;
        }
        else{
            total = total + guys[i];
        }
    }
    average = total/5;
    printf("%d", average);
    return 0;
}
