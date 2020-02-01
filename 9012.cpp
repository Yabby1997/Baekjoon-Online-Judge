#include<iostream>

using std::cout;
using std::endl;
using std::cin;

class Stack{
private:
    char* stack;
    int size;
public:
    Stack() : size(0){
        stack = new char[50];
    }
    
    char top(){
        return stack[size - 1];
    }
    
    void pop(){
        size--;
    }
    
    void push(char newChar){
        stack[size] = newChar;
        size++;
    }
    
    int isEmpty(){
        if(size == 0)  
            return 1;
        else
            return 0;
    }
};

void stackControl(Stack* stack, char command){
    if(stack->top() == '(' && command == ')')
        stack->pop();
    else
        stack->push(command);
}

int main(void){
    int numOfCases;
    cin>>numOfCases;
    for(int i = 0; i < numOfCases; i++){
        Stack* stack = new Stack();
        char inputString[100];
        cin>>inputString;
        for(int j = 0; inputString[j] != '\0'; j++){
            stackControl(stack, inputString[j]);
        }
        if(stack->isEmpty() == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
