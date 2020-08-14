#include<stdio.h>
#include<vector>

using namespace std;

int row, col, numOfCabbages;
bool matrix[50][50];
bool visited[50][50];
int numOfTests;
int cluster = 0;

void reset();
void init();
void findRecursively(int x, int y);
void solve();

int main(){
    scanf("%d", &numOfTests);
    solve();
}

void reset(){
    cluster = 0;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            matrix[i][j] = false;
            visited[i][j] = false;
        }
    }
}

void init(){
    reset();
    scanf("%d %d %d", &row, &col, &numOfCabbages);
    for(int i = 0; i < numOfCabbages; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        matrix[from][to] = true;
    }
}

void findRecursively(int x, int y){
    if(x < 0 || x > row - 1 || y < 0 || y > col - 1 || visited[x][y])
        return;
    else if(matrix[x][y]){
        visited[x][y] = true;
        findRecursively(x, y - 1);
        findRecursively(x, y + 1);
        findRecursively(x - 1, y);
        findRecursively(x + 1, y);
    }
}

void solve(){
    vector<int> results;
    for(int i = 0; i < numOfTests; i++){
        init();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j] && matrix[i][j]){
                    findRecursively(i, j);
                    cluster++;
                }
            }
        }
        results.push_back(cluster);
    }
    for(int i = 0; i < results.size(); i++){
        printf("%d\n", results[i]);
    }
}

