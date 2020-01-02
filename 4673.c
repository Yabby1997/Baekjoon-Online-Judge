#include<stdio.h>

int kaprekarFunc(int givenNumber);

int main(){
    int kaprekarArray[30000] = {0, };                                                   //initialize all member of array with 0
                                                                                        //num created by kaprekarFunc exceed 10000. so if you limits size of array 10000, segmentation fault occurs.
    for(int i = 1; i < 10000; i++)  kaprekarArray[kaprekarFunc(i)]++;                   //num created by karprekarFunc is index of kaprekarArray and value of each member of kaprekarArray means # of "creater" of that index 
    for(int i = 1; i < 10000; i++)  if(kaprekarArray[i] == 0)   printf("%d\n", i);      //ith value of kaprekarArray means how many creater it has. so if it is equals to 0, i is "self number"
    return 0;
}

int kaprekarFunc(int givenNumber){
    int j = givenNumber/1000;
    int k = (givenNumber-j*1000)/100;
    int m = (givenNumber-j*1000-k*100)/10;
    int n = (givenNumber-j*1000-k*100-m*10)%10;
    
    return givenNumber+j+k+m+n;
}
