#include<iostream>
#include<stack>

using namespace std;

int numOfCommands;
stack<int> tempStack;

void inputStack();
void showStack();
void push();
void top();
void size();
void empty();
void pop();

int main(){
	inputStack();
	return 0;
}

void inputStack(){
	cin>>numOfCommands;
	for(int i = 0; i < numOfCommands; i++){
		string command;
		int number;
		cin>>command;
		if(command == "push")
			push();
		else if(command == "top")
			top();
		else if(command == "size")
			size();
		else if(command == "empty")
			empty();
		else if(command == "pop")
			pop();
	}
}

void push(){
	int number;
	cin>>number;
	tempStack.push(number);
}

void top(){
	if(tempStack.size() == 0)
		cout<<-1<<endl;
	else
		cout<<tempStack.top()<<endl;
}

void size(){
	cout<<tempStack.size()<<endl;
}

void empty(){
	int value = 0;
	if(tempStack.size() == 0)
		value = 1;
	cout<<value<<endl;
}

void pop(){
	if(tempStack.size() == 0)
		cout<<-1<<endl;
	else{
		cout<<tempStack.top()<<endl;
		tempStack.pop();
	}
}

