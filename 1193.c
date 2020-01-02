#include<stdio.h>

int main(){
    int number = 0;
    int iteration = 0;
    
    scanf("%d", &number);
    
    while(number > 0){
        iteration++;
        number = number - iteration;
    }
    
    if(iteration % 2 == 1){
        printf("%d/%d", 1 - number, number + iteration);
    }
    else{
        printf("%d/%d", number + iteration, 1 - number);
    }
    return 0;
}
