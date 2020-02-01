#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

class Queue{
private:
    int queue[10000] = {0, };
    int size;
public:
    Queue(){
        size = 0;
    }
    
    void push(int pushNum){
        queue[size] = pushNum;
        size++;
    }
    
    void pop(){
        if(size == 0)
            cout<<-1<<endl;
        else{
            cout<<queue[0]<<endl;
            size--;
            for(int i = 0; i < size; i ++)
                queue[i] = queue[i+1];
        }
    }
    
    void showSize(){
        cout<<size<<endl;
    }
    
    void isEmpty(){
        int result = 0;
        if(size == 0)
            result = 1;
        cout<<result<<endl;
    }
    
    void showFront(){
        int result = queue[0];
        if(size == 0)
            result = -1;
        cout<<result<<endl;
    }
    
    void showBack(){
        int result = -1;
        if(size != 0)
            result = queue[size - 1];
        cout<<result<<endl;
    }
};

int main(void){
    Queue* mainQueue = new Queue();
    int numOfCommands;
    cin>>numOfCommands;
    
    for(int i = 0; i < numOfCommands; i++){
        char command[5];
        cin>>command;
        
        if(strcmp(command, "push") == 0){
            int pushNum;
            cin>>pushNum;
            mainQueue->push(pushNum);    
        }
        else if(strcmp(command, "pop") == 0)
            mainQueue->pop();
        else if(strcmp(command, "empty") == 0)
            mainQueue->isEmpty();
        else if(strcmp(command, "size") == 0)
            mainQueue->showSize();
        else if(strcmp(command, "front") == 0)
            mainQueue->showFront();
        else if(strcmp(command, "back") == 0)
            mainQueue->showBack();
    }
    return 0;
}
