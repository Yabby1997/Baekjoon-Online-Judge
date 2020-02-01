#include<stdio.h>

int main(){
    int inputMelody[8] = {0, };
    int melodyChecker[8] = {0, };
    int output = 0;
    for(int i = 0; i < 8; i++){
        scanf("%d", &inputMelody[i]);
    }
    for(int i = 0; i < 8; i++){
        melodyChecker[i] = inputMelody[i+1] - inputMelody[i];
    }
    for(int i = 1; i < 7; i++){
        if(melodyChecker[i] == melodyChecker[i-1]){
            output = melodyChecker[i];
        }
        else{
            output = 0;
            break;
        }
    }
    
    switch(output){
        case 0 :
            printf("mixed");
            break;
        case 1 :
            printf("ascending");
            break;
        case -1 :
            printf("descending");
            break;
    }
    return 0;
}
