#include<stdio.h>

int main(){
    int score = 0;
    scanf("%d", &score);
    if(score < 0 || score >100){
        printf("시험 점수는 0~100점 사이의 값이 입력되어야 합니다.\n");
        return 0;
    }
    
    else{
        if(score >= 90)
            printf("A\n");
        else if(score >= 80)
            printf("B\n");
        else if(score >= 70)
            printf("C\n");
        else if(score >= 60)
            printf("D\n");
        else
            printf("F\n");
    }
    return 0;
}
