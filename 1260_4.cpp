#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

vector<vector<bool>> matrix(1001, vector<bool>(1001, false));
vector<bool> visited(1001, false);

int numOfVertices, numOfEdges, startingVertex;

void input();
void DFS(int current);
void clear();
void BFS();

int main(){
    input();
    DFS(startingVertex);
    clear();
    BFS();
    return 0;
}

void input(){
    scanf("%d %d %d", &numOfVertices, &numOfEdges, &startingVertex);
    for(int i = 0; i < numOfEdges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        matrix[from][to] = true;
        matrix[to][from] = true;
    }
}

void clear(){
    for(int i = 1; i <= numOfVertices; i++){
        visited[i] = false;
    }
    printf("\n");
}

void DFS(int current){
    printf("%d ", current);
    visited[current] = true;
    for(int i = 1; i <= numOfVertices; i++){
        if(matrix[current][i] && !visited[i])
            DFS(i);
    }
}

void BFS(){
    queue<int> tempQueue;
    tempQueue.push(startingVertex);
    while(!tempQueue.empty()){
        int current = tempQueue.front();
        tempQueue.pop();
        if(visited[current])
            continue;
        printf("%d ", current);
        visited[current] = true;
        for(int i = 1; i <= numOfVertices; i++){
            if(matrix[current][i] && !visited[i])
                tempQueue.push(i);
        }
    }
}
