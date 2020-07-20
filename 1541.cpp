#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

int operand = 0;
string temp;
bool isAdd = false;
vector<int> subtractionVector;

int main(){
    string input;
    cin>>input;
    
    for(int i = 0; i < input.size(); i++){
        if(input[i] != '+' && input[i] != '-'){
            temp.push_back(input[i]);
        }
        else{
            if(isAdd){
                operand = operand + stoi(temp);
                isAdd = false;
            }
            else{
                operand = stoi(temp);
            }
            temp = "";
            if(input[i] == '+'){
                isAdd = true;
            }
            else if(input[i] == '-'){
                subtractionVector.push_back(operand);
                isAdd = false;
                operand = 0;
            }
        }
    }
    subtractionVector.push_back(operand + stoi(temp));
    
    for(int i = 1; i < subtractionVector.size(); i++){
        subtractionVector[0] -= subtractionVector[i];
    }
    
    cout<<subtractionVector[0]<<endl;
    
    return 0;
}
