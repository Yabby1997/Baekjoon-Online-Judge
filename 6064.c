#include<stdio.h>

int calculate(int M, int N, int X, int Y);
int gcd(int a, int b);
int lcm(int a, int b);

int main(){
    int numOfCases = 0;
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        int M, N, X, Y;
        scanf("%d %d %d %d", &M, &N, &X, &Y);
        printf("%d\n", calculate(M, N, X, Y));
    }
    return 0;
}

int calculate(int maximumX, int maximumY, int inputX, int inputY){
    if(inputX > maximumX || inputY > maximumY || inputX > 40000 || inputY > 40000 || inputX == 0 || inputY == 0)
        return -1;
    int year = inputX;
    int key = lcm(maximumX, maximumY);
    int i = 0;
    while(1){
        int yearY = year % maximumY == 0 ? maximumY : year % maximumY;
        //printf("year : %d, yearY : %d\n", year, yearY);
        if(yearY == inputY){
            //printf("@ terminated by meeting end @       inputY : %d, yearY : %d\n", inputY, yearY);
            break;
        }
        i++;
        year = year + maximumX;
        if(year > key){
            //printf("@ terminated by exceeding LCM @     inputY : %d, yearY : %d\n", inputY, yearY);
            return -1;
        }
    }
    return year;
}

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int lcm(int a, int b) {
    int result = a * b / gcd(a, b);
    return result;
}
