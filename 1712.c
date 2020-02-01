#include<stdio.h>

int main(){
    int infraCost = 0;
    int productionCost = 0;
    int productPrice = 0;
    int breakEvenQtt = 0;
    
    scanf("%d %d %d", &infraCost, &productionCost, &productPrice);
    
    if(productPrice - productionCost <= 0)
        breakEvenQtt = -1;
    else
        breakEvenQtt = infraCost/(productPrice - productionCost) + 1;
        
    printf("%d", breakEvenQtt);
    return 0;
}
