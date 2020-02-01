#include<stdio.h>

int main(){
    int sugarAmount, output = 0;
    
    scanf("%d", &sugarAmount);
    
    while(1){
        if(sugarAmount % 5 == 0){
            printf("%d", output + sugarAmount/5);
            break;
        }
        else if(sugarAmount < 0){
            printf("-1");
            break;
        }
        sugarAmount -= 3;
        output++;
    }
    return 0;
}
