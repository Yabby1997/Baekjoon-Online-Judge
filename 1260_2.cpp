#include<stdio.h>
#include<queue>

using namespace std;

bool matrix[1001][1001] = {false, };
bool visited[1001] = {false, };

int numOfVertices, numOfEdges, startingVertex;
void input();
void resetVisited();
void BFS();
void DFS(int currentVertex);

int main(){
    input();
    DFS(startingVertex);
    resetVisited();
    BFS();
    return 0;
}

void input(){
    scanf("%d %d %d", &numOfVertices, &numOfEdges, &startingVertex);
    for(int i = 0; i < numOfEdges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        matrix[from][to] = matrix[to][from] = true;
        
    }
}

void resetVisited(){
    for(int i = 1; i <= numOfVertices; i++){
        visited[i] = false;
    }
}

void BFS(){
    printf("\n");
    queue<int> tempQueue;
    printf("%d ", startingVertex);
    tempQueue.push(startingVertex);
    visited[startingVertex] = true;
    while(!tempQueue.empty()){
        int vertex = tempQueue.front();
        tempQueue.pop();
        for(int i = 1; i <= numOfVertices; i++){
            if(matrix[vertex][i] && !visited[i]){
                printf("%d ", i);
                tempQueue.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int currentVertex){
    printf("%d ", currentVertex);
    visited[currentVertex] = true;
    for(int i = 1; i <= numOfVertices; i++){
        if(matrix[currentVertex][i] && !visited[i]){
            DFS(i);
        }
    }
}

