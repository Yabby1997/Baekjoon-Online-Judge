#include<stdio.h>

char starArray[3072][6143];     //global variable [y][x]

void initializeArray();
void printStar(int givenNumber);
void drawStar(int scale, int yPosition, int xPosition);

int main(){
    int inputNumber;
    scanf("%d", &inputNumber);
    
    initializeArray();
    drawStar(inputNumber, 0, inputNumber-1);
    printStar(inputNumber);

    return 0;
}

void initializeArray(){
    for(int i = 0; i < 3072; i++)   for(int j = 0; j < 6143; j++)   starArray[i][j] = ' ';          //initialize all members of starArray with "space"
}

void printStar(int givenNumber){                                                                    //print starArray
    for(int i = 0; i < givenNumber; i++){
        for(int j = 0; j < givenNumber*2-1; j++){
            printf("%c", starArray[i][j]);
        }
        printf("\n");
    }    
}

void drawStar(int scale, int yPosition, int xPosition){                                             //function devide scale to half recursively. when arrive specific scale(base), draw pyramid
    if(scale == 3){                                                                                 //base pyramid is level 3 pyramid
        starArray[yPosition][xPosition] = '*';
        starArray[yPosition+1][xPosition-1] = '*';
        starArray[yPosition+1][xPosition+1] = '*';
        starArray[yPosition+2][xPosition-2] = '*';
        starArray[yPosition+2][xPosition-1] = '*';
        starArray[yPosition+2][xPosition] = '*';
        starArray[yPosition+2][xPosition+1] = '*';
        starArray[yPosition+2][xPosition+2] = '*';
    }
    else{                                                                                           //there's two pyramids under one pyramids with half scale
        drawStar(scale/2, yPosition, xPosition);
        drawStar(scale/2, yPosition + scale/2, xPosition - scale/2);
        drawStar(scale/2, yPosition + scale/2, xPosition + scale/2);
    }
}
