#include<stdio.h>

int main(){
    int cellNumber = 0;
    int cellAmount = 1;
    int level = 0;
    scanf("%d", &cellNumber);
    
    if(cellNumber == 1)
        level = 1;
    else
        for(level; cellAmount < cellNumber; level++)
            cellAmount = cellAmount + 6 * level;
    
    printf("%d", level);
    
    return 0;
}
