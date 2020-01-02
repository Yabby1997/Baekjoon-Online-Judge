#include<iostream>
#include<vector>

using namespace std;

int main(void){
    vector<string> resultVector;
    int numOfInput;
    char lastChar;
    cin>>numOfInput;
    for(int i = 0; i < numOfInput; i++){
        string temp;
        cin>>temp;
        lastChar = temp.back();
        if(lastChar == 'a'){
            temp.pop_back();
            temp.insert(temp.size(), "as");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'i' || lastChar == 'y'){
            temp.pop_back();
            temp.insert(temp.size(), "ios");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'l'){
            temp.pop_back();
            temp.insert(temp.size(), "les");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'n'){
            temp.pop_back();
            temp.insert(temp.size(), "anes");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'e' && *(temp.end() - 2) == 'n'){
            temp.pop_back();
            temp.pop_back();
            temp.insert(temp.size(), "anes");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'o'){
            temp.pop_back();
            temp.insert(temp.size(), "os");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'r'){
            temp.pop_back();
            temp.insert(temp.size(), "res");
            resultVector.push_back(temp);
        }
        else if(lastChar == 't'){
            temp.pop_back();
            temp.insert(temp.size(), "tas");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'u'){
            temp.pop_back();
            temp.insert(temp.size(), "us");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'v'){
            temp.pop_back();
            temp.insert(temp.size(), "ves");
            resultVector.push_back(temp);
        }
        else if(lastChar == 'w'){
            temp.pop_back();
            temp.insert(temp.size(), "was");
            resultVector.push_back(temp);
        }
        else{
            temp.insert(temp.size(), "us");
            resultVector.push_back(temp);
        }
    }
    for(vector<string>::iterator i = resultVector.begin(); i < resultVector.end(); i++)
        cout<<*i<<endl;
    return 0;
}
