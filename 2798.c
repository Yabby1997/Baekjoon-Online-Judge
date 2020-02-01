#include<stdio.h>

int main(){
    int numOfCards, maxSum;
    int bestRecord = 0;
    int cards[100] = {0, };
    
    scanf("%d %d", &numOfCards, &maxSum);
    for(int i = 0; i < numOfCards; i++)
        scanf("%d", &cards[i]);
    
    for(int i = 0; i < numOfCards; i++){
        for(int j = i + 1; j < numOfCards; j++){
            for(int k = j + 1; k < numOfCards; k++){
                if(maxSum == cards[k] + cards[j] + cards[i]){
                    bestRecord = maxSum;
                    break;
                }
                else if(maxSum > cards[k] + cards[j] + cards[i] && cards[k] + cards[j] + cards[i] > bestRecord)
                    bestRecord = cards[k] + cards[j] + cards[i];
            }
        }
    }
    printf("%d", bestRecord);
    return 0;
}
