#include<stdio.h>

/*
croatian alphabet   |   alphabet    |   represent by..
    č	            |       c=      |      1
    ć	            |       c-      |      2
    dž              |	    dz=     |      3
    đ               |   	d-      |      4
    lj              |	    lj      |      5
    nj              |	    nj      |      6
    š               |	    s=      |      7
    ž	            |       z=      |      8
*/

int main(){
    char inputString[100] = "";
    char croatianString[100] = "";
    int checkIndex = 0;
    int croatianIndex = 0;
    int croatianCounter = 0;
    
    scanf("%s", inputString);
    
    while(inputString[checkIndex] != '\0'){                                                         //THIS LOOP MAKES CROATIANSTRING OUT OF INPUTSTRING
        if(inputString[checkIndex] == 'c'){
            if(inputString[checkIndex + 1] == '='){
                croatianString[croatianIndex++] = '1';
                checkIndex = checkIndex + 2;
            }
            else if(inputString[checkIndex + 1] == '-'){
                croatianString[croatianIndex++] = '2';
                checkIndex = checkIndex + 2;
            }
            else
                croatianString[croatianIndex++] = inputString[checkIndex++];
        }
        else if(inputString[checkIndex] == 'd'){
            if(inputString[checkIndex + 1] == 'z' && inputString[checkIndex + 2] == '='){
                croatianString[croatianIndex++] = '3';
                checkIndex = checkIndex + 3;
            }
            else if(inputString[checkIndex + 1] == '-'){
                croatianString[croatianIndex++] = '4';
                checkIndex = checkIndex + 2;
            }
            else
                croatianString[croatianIndex++] = inputString[checkIndex++];
        }
        else if(inputString[checkIndex] == 'l' && inputString[checkIndex + 1] == 'j'){
            croatianString[croatianIndex++] = '5';
            checkIndex = checkIndex + 2;
        }
        else if(inputString[checkIndex] == 'n' && inputString[checkIndex + 1] == 'j'){
            croatianString[croatianIndex++] = '6';
            checkIndex = checkIndex + 2;
        }
        else if(inputString[checkIndex] == 's' && inputString[checkIndex + 1] == '='){
            croatianString[croatianIndex++] = '7';
            checkIndex = checkIndex + 2;
        }
        else if(inputString[checkIndex] == 'z' && inputString[checkIndex + 1] == '='){
            croatianString[croatianIndex++] = '8';
            checkIndex = checkIndex + 2;
        }
        else
            croatianString[croatianIndex++] = inputString[checkIndex++];
    }
    
    for(int i = 0; croatianString[i] != '\0'; i++)                                                  //COUNT LENGTH OF CROATIANSTRING
        croatianCounter++;
    
    printf("%d", croatianCounter);
    
    return 0;
}
