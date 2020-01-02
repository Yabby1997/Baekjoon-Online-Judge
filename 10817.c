#include<stdio.h>

int main(){
    int sortArray[3];
    int sizeOfArray = sizeof(sortArray)/sizeof(sortArray[0]);
    scanf("%d %d %d", &sortArray[0], &sortArray[1], &sortArray[2]);
    
    //i가 0일때 마지막 인덱스에 최댓값을 저장하도록 2중 for문이 돈다.
    //i가 1일때 마지막-1 인덱스에 두번째로 큰 값을 저장하도록 2중 for문이 돈다.
    //... (bubble정렬)
    for(int i = 0; i < sizeOfArray-1; i++){
        for(int j = 0; j < sizeOfArray-1-i; j++){
            if(sortArray[j] > sortArray[j+1]){
                int temp = sortArray[j+1];
                sortArray[j+1] = sortArray[j];
                sortArray[j] = temp;
            }             
        }       
    }

    printf("%d", sortArray[1]);
    
    return 0;
}
