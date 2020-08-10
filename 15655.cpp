#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> numbers;
vector<int> temp = {-1};
vector<bool> visited;

void input();
void solveRecursively(int index);

int main(){
    input();
    sort(numbers.begin(), numbers.end());
    solveRecursively(0);
    return 0;
}

void input(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        numbers.push_back(input);
        visited.push_back(false);
    }
}

void solveRecursively(int index){
    if(index == m){
        for(int i = 1; i < temp.size(); i++){
            printf("%d ", temp[i]);
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < numbers.size(); i++){
            if(!visited[i] && (numbers[i] > temp[index])){
                visited[i] = true;
                temp.push_back(numbers[i]);
                solveRecursively(index + 1);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
}

