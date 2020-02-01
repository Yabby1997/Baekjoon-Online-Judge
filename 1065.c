#include<stdio.h>

int checkNum(int givenNumber);

int main(){
    int givenNumber;
    scanf("%d", &givenNumber);
    if(givenNumber < 1 || givenNumber > 1000)   return 0;
    else    printf("%d", checkNum(givenNumber));
    return 0;
}

int checkNum(int givenNumber){
    int counter = 0;
    for(int currentNumber = 1; currentNumber < givenNumber+1; currentNumber++){
        int j = currentNumber/1000;
        int k = (currentNumber-j*1000)/100;
        int m = (currentNumber-j*1000-k*100)/10;
        int n = currentNumber-j*1000-k*100-m*10;
        
        if(j == 0 && k == 0)  counter++;
        else if(j == 0 && k-m == m-n)  counter++;         
    }
	return counter;
}
