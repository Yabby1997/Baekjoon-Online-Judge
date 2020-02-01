#include<stdio.h>

int main(){
    int remainderArray[42] = {0, };
    int counter = 0;
    
    for(int i = 0; i < 10; i++){
        int tempIn;
        scanf("%d", &tempIn);
        remainderArray[tempIn%42]++;
    }
    
    for(int i = 0; i < 42; i++){
        if(remainderArray[i] != 0)
            counter++;
    }
    
    printf("%d", counter);
    
    return 0;
}
