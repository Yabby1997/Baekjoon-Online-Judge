#include<stdio.h>
#include<string.h>

void push(int x);
int pop();
int size();
int empty();
int top();

int cases[10000] = {0, };

int main(){
    int numOfCases = 0;
    char command[10] = "";
    
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        scanf("%s", command);
        if(strcmp(command, "push") == 0){
            int pushN;
            scanf("%d", &pushN);
            push(pushN);
        }
        else if(strcmp(command, "pop") == 0)
            printf("%d\n", pop());
        else if(strcmp(command, "size") == 0)
            printf("%d\n", size());
        else if(strcmp(command, "empty") == 0)
            printf("%d\n", empty());
        else if(strcmp(command, "top") == 0)
            printf("%d\n", top());
    }
    return 0;
}

void push(int x){
    cases[size()] = x;    
}

int pop(){
    if(size() == 0)
        return -1;
    else{
        int temp = cases[size() - 1];
        cases[size() - 1] = 0;
        return temp;
    }
}

int size(){
    int i = 0;
    while(cases[i] != 0)
        i++;
    return i;
}

int top(){
    if(size() < 1)
        return -1;
    else
        return cases[size() - 1];
}

int empty(){
    if(size() == 0)
        return 1;
    else
        return 0;
}
