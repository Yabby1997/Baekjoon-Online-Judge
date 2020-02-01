#include<stdio.h>

int alphaCentauri(int distance);

int main(){
    int numOfInput, departure, destination;
    scanf("%d", &numOfInput);
    for(int i = 0; i < numOfInput; i++){
        scanf("%d %d", &departure, &destination);
        printf("%d\n", alphaCentauri(destination - departure));
    }
    return 0;
}

int alphaCentauri(int distance){
    int i = 1;
    int result;
    while(1){
        distance = distance - i;            //I JUMPS
        if(distance <= 0){                  //IF IN RANGE OF I JUMPS
            result = 2 * i - 1;             
            break;
        }
        distance = distance - i;            //ADDITIONAL I JUMPS
        if(distance <= 0){                  //IN RANGE OF ADDITIONAL I JUMPS
            result = 2 * i;
            break;
        }
        i++;
    }
    return result;
}
