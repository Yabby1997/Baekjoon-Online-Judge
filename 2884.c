#include<stdio.h>

int main(){
    int inHour, inMinute, outHour, outMinute;
    scanf("%d %d", &inHour, &inMinute);
    if(inMinute < 45){
        outMinute = 15 + inMinute;
        outHour = inHour - 1;
    }
    else{
        outMinute = inMinute - 45;
        outHour = inHour;
    }
    
    if(outHour < 0){
        outHour = 24 + outHour;
    }
    
    printf("%d %d", outHour, outMinute);
    return 0;
}
