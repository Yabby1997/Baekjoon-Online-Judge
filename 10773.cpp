#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Stack{
private:
    int* stack;
    int size;
public:
    Stack(int newSize){
        stack = (int*)malloc(sizeof(int)*newSize);
        size = 0;
    }
    
    void push(int newValue){
        stack[size] = newValue;
        size++;
    }
    
    void pop(){
        size--;
    }
    
    int sum(){
        int result = 0;
        for(int i = 0; i < size; i ++){
            result = result + stack[i];
        }
        return result;
    }
    
    int showSize(){
        return size;
    }
};

int main(void){
    int sizeOfStack;
    cin>>sizeOfStack;
    Stack* stack = new Stack(sizeOfStack);
    for(int i = 0; i < sizeOfStack; i ++){
        int inputValue;
        cin>>inputValue;
        if(inputValue == 0)
            stack->pop();
        else
            stack->push(inputValue);
    }
    cout<<stack->sum()<<endl;
    return 0;
}
