#include<stdio.h>
#include<math.h>

int main(){
    double up, down, distance;          
    scanf("%lf %lf %lf", &up, &down, &distance);                                //FORMAT OF DOUBLE IS %LF
    int numOfDays = (int)ceil((distance - up)/(up - down)) + 1;                 //LAST ONE MOVE CAN REPLACED WITH FULLY UP (NOT INCLUDE DOWN) AND OTHER MOVES ARE SUM OF UP AND DOWN
    printf("%d", numOfDays);                                                    //USE CEIL WITH DOUBLE VARIABLES
}
