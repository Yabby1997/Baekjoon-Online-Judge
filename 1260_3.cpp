#include<stdio.h>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

using namespace std;

int numOfVertices = 0, numOfEdges = 0, startingVertex = 0;
vector<vector<int>> adjacencyList(1001, vector<int>());
vector<bool> visited(1001, false);

void input();
void DFS(int current);
void BFS();
void clear();

int main(){
    input();
    DFS(startingVertex);
    clear();
    BFS();
}

void input(){
    scanf("%d %d %d", &numOfVertices, &numOfEdges, &startingVertex);
    for(int i = 0; i < numOfEdges; i++){
        int from = 0, to = 0;
        scanf("%d %d", &from, &to);
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }
    for(int i = 0; i < numOfVertices; i++){
        sort(adjacencyList[i].begin(), adjacencyList[i].end());
    }
}

void DFS(int current){
    printf("%d ", current);
    visited[current] = true;
    for(int i = 0; i < adjacencyList[current].size(); i++){
        int next = adjacencyList[current][i];
        if(!visited[next])
            DFS(next);
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
        for(int i = 0; i < adjacencyList[current].size(); i++){
            if(!visited[adjacencyList[current][i]])
                tempQueue.push(adjacencyList[current][i]);
        }
    }
}

void clear(){
    for(int i = 1; i <= numOfVertices; i++){
        visited[i] = false;
    }
    printf("\n");
}

