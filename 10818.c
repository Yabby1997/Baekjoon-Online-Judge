#include<stdio.h>

int main(){
    int numOfCases = 0;
    scanf("%d", &numOfCases);
    int nums[numOfCases];
    
    for(int i = 0; i < numOfCases; i++)
        scanf("%d", &nums[i]);
    
    int minimum = nums[0];
    int maximum = nums[0];
    
    for(int i = 0; i < numOfCases; i++){
        if(nums[i] > maximum)
            maximum = nums[i];
        else if(nums[i] < minimum)
            minimum = nums[i];
    }
    printf("%d %d", minimum, maximum);
    return 0;
}
