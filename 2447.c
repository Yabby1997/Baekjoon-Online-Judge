#include<stdio.h>
#define MAX 6561

char matrix[MAX][MAX];

void arrayInitializer(int scale);
void setStarRecursively(int yPos, int xPos, int level);
void drawStar(int scale);

int main(){
    int inputNum;
    scanf("%d", &inputNum);
    arrayInitializer(inputNum);
    setStarRecursively(0, 0, inputNum);
    drawStar(inputNum);
    return 0;
}

void arrayInitializer(int scale){
    for(int i = 0; i < scale; i++){
        for(int j = 0; j < scale; j++){
            matrix[i][j] = ' ';
        }
    }
}
void setStarRecursively(int yPos, int xPos, int level){
    if(level == 3){
        matrix[yPos][xPos] = '*'; matrix[yPos][xPos+1] = '*';   matrix[xPos][yPos+2] = '*';
        matrix[yPos+1][xPos] = '*'; matrix[xPos+1][yPos+2] = '*';
        matrix[yPos+2][xPos] = '*'; matrix[yPos+2][xPos+1] = '*';   matrix[xPos+2][yPos+2] = '*';
    }
    else{
        int downScale = level/3;
        setStarRecursively(yPos, xPos, downScale); setStarRecursively(yPos+downScale, xPos, downScale); setStarRecursively(yPos+downScale*2, xPos, downScale);
        setStarRecursively(yPos, xPos+downScale, downScale); setStarRecursively(yPos+downScale*2, xPos+downScale, downScale);
        setStarRecursively(yPos, xPos+downScale*2, downScale); setStarRecursively(yPos+downScale, xPos+downScale*2, downScale); setStarRecursively(yPos+downScale*2, xPos+downScale*2, downScale);
    }
}

void drawStar(int scale){
    for(int i = 0; i < scale; i++){
        for(int j = 0; j < scale; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
