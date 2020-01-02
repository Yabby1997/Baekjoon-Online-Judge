#include<stdio.h>

int main(){
    int numOfCases = 0;
    int cases[100] = {0, };
    int counter = 0;
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        scanf("%d", &cases[i]);
    }
    for(int i = 0; i < numOfCases; i++){
        int j = 2;
        while(1){
            if(cases[i] == 1){
                //printf("@1 detected! (not prime)\n");
                break;
            }
            else if(j == cases[i]){
                //printf("@%d is prime number. it only includes itself!\n", j);
                counter++;
                break;
            }
            else if(cases[i] % j == 0){
                //printf("@%d is not prime numbeer. it is %d x %d = %d\n", cases[i], j, cases[i]/j, cases[i]);
                break;
            }
            else if(j > cases[i])
                break;
            j++;
        }
    }
    printf("%d", counter);
    return 0;
}
