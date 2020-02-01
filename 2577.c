#include<stdio.h>

int main(){
    int A, B, C, ABC;
    int checkArray[10] = {0, };
    char ABCstring[9];
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    sprintf(ABCstring, "%d", A*B*C);
    for(int i = 0; ABCstring[i] != '\0'; i++){
        if(ABCstring[i] == '0')   checkArray[0]++;
        else if(ABCstring[i] == '1')   checkArray[1]++;
        else if(ABCstring[i] == '2')   checkArray[2]++;
        else if(ABCstring[i] == '3')   checkArray[3]++;
        else if(ABCstring[i] == '4')   checkArray[4]++;
        else if(ABCstring[i] == '5')   checkArray[5]++;
        else if(ABCstring[i] == '6')   checkArray[6]++;
        else if(ABCstring[i] == '7')   checkArray[7]++;
        else if(ABCstring[i] == '8')   checkArray[8]++;
        else    checkArray[9]++;
    }
    for(int i = 0; i < 10; i++) printf("%d\n", checkArray[i]);
    return 0;
}
