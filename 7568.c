#include<stdio.h>

int main(){
    int numOfCases, caseWeight, caseHeight;
    int weight[50] = {0, };
    int height[50] = {0, };
    int result[50] = {0, };
    
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++)
        scanf("%d %d", &weight[i], &height[i]);
        
    for(int i = 0; i < numOfCases; i++){
        int counter = 1;
        for(int j = 0; j < numOfCases; j++){
            if(weight[j] > weight[i] && height[j] > height[i])
                counter++;
        }
        result[i] = counter;
    }
    
    for(int i = 0; i < numOfCases; i ++){
        printf("%d ", result[i]);
    }
    return 0;
}
