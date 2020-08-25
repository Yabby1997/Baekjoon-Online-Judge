#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int m, n, h, currentSize = 0, nextSize = 0, iteration = 0;
int tomatoes[100][100][100];
bool visited[100][100][100] = {false, };
int xDistance[] = {1, -1, 0, 0, 0, 0};
int yDistance[] = {0, 0, 1, -1, 0, 0};
int zDistance[] = {0, 0, 0, 0, 1, -1};
queue<vector<int>> tempQueue;

void input();
void solve();
void BFS();
void spread(int i, int j, int k);
void showResult();

int main(){
    input();
    BFS();
    showResult();
    return 0;
}

void input(){
    int empty = 0;
    scanf("%d %d %d", &m, &n, &h);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                int tomato;
                scanf("%d", &tomato);
                tomatoes[i][j][k] = tomato;
                if(tomato == -1)
                    empty++;
                else if(tomato == 1){
                    tempQueue.push(vector<int>{i, j, k});
                    currentSize++;
                }
            }
        }
    }
}

void BFS(){
    while(!tempQueue.empty()){
        nextSize = 0;
        for(int i = 0; i < currentSize; i++){
            vector<int> temp = tempQueue.front();
            tempQueue.pop();
            for(int i = 0; i < 6; i++){
                spread(temp[0] + xDistance[i], temp[1] + yDistance[i], temp[2] + zDistance[i]);
            }
        }
        currentSize = nextSize;
        iteration++;
    }
}

void spread(int i, int j, int k){
    if(i >= 0 && i < h && j >= 0 && j < n && k >= 0 && k < m && !visited[i][j][k] && tomatoes[i][j][k] == 0){
        tempQueue.push(vector<int>{i, j, k});
        visited[i][j][k] = true;
        tomatoes[i][j][k] = 1;
        nextSize++;
    }
}

void showResult(){
    int result = iteration - 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(tomatoes[i][j][k] == 0){
                    result = -1;
                }
            }
        }
    }
    printf("%d\n", result);
}

