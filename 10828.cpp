#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

class Node{
private :
    Node* front;
    int value;
public :
    Node(Node* newFront, int newValue) : front(newFront), value(newValue) {}
    void addNode(Node* newFront){
        this->front = newFront;
    }
    void setFront(Node* newFront){
        this->front = newFront;
    }
    Node* getFront(){
        return this->front;
    }
    int getValue(){
        return this->value;
    }
    bool isBottom(){
        if(this->front == NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

class Stack{
private :
    int size;
    Node* top;
public :
    Stack(){
        size = 0;
        top = NULL;
    }
    void push(int pushNumber){
        Node* newNode = new Node(NULL, pushNumber);
        if(top == NULL)
            top = newNode;
        else{
            newNode->setFront(top);
            top = newNode;
        }
        size++;
    }
    
    void pop(){
        if(size != 0){
            cout<<top->getValue()<<endl;
            top = top->getFront();
            top->~Node();
            size--;
        }
        else
            cout<<-1<<endl;
    }
    
    void showSize(){
        cout<<size<<endl;
    }
    
    void isEmpty(){
        if(size == 0)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    
    void showTop(){
        if(size == 0)
            cout<<-1<<endl;
        else
            cout<<top->getValue()<<endl;
    }
};

int main(void){
    Stack *a = new Stack;
    int numOfCases;
    cin>>numOfCases;
    for(int i = 0; i < numOfCases; i++){
        char* command = new char[5];
        cin>>command;
        if(strcmp(command, "push") == 0){
            int pushNum;
            cin>>pushNum;
            a->push(pushNum);
        }
        else if(strcmp(command, "pop") == 0)
            a->pop();
        else if(strcmp(command, "top") == 0)
            a->showTop();
        else if(strcmp(command, "size") == 0)
            a->showSize();
        else if(strcmp(command, "empty") == 0)
            a->isEmpty();
        delete[] command;
    }
    return 0;
}
