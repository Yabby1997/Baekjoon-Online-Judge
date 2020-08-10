#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int L, C;
string characters;
string temp;
bool visited[15] = {false, };

void input();
void solveRecursively(int index);
bool valid();

int main(){
    input();
    sort(characters.begin(), characters.end());
    solveRecursively(0);
    return 0;
}

void input(){
    cin>>L>>C;
    for(int i = 0; i < C; i++){
        char input;
        cin>>input;
        characters.push_back(input);
    }
}

void solveRecursively(int index){
    if(index == L && valid()){
        cout<<temp<<endl;
    }
    else{
        for(int i = 0; i < characters.size(); i++){
            if(visited[i] || characters[i] < temp[index - 1]){
                continue;
            }
            temp.push_back(characters[i]);
            visited[i] = true;
            solveRecursively(index + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

bool valid(){
    int vowelCount = 0;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
            vowelCount++;
    }
    return (vowelCount >= 1 && (temp.size() - vowelCount) >= 2);
}
