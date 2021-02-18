#include<stdio.h>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

int numOfVertices = 0, numOfEdges = 0, startingVertex = 0;
vector<vector<int>> adjacencyList(1001, vector<int>());
vector<bool> visited(1001, false);

void input();
void DFS();
void BFS();
void clear();

int main(){
    input();
    DFS();
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

void DFS(){
    deque<int> queue;
    queue.push_front(startingVertex);
    while(queue.size() != 0){
        int current = queue.front();
        queue.pop_front();
        if(visited[current])
            continue;
        printf("%d ", current);
        visited[current] = true;
        queue.insert(queue.begin(), adjacencyList[current].begin(), adjacencyList[current].end());
    }
}

void BFS(){
    deque<int> queue;
    queue.push_front(startingVertex);
    while(queue.size() != 0){
        int current = queue.front();
        queue.pop_front();
        if(visited[current])
            continue;
        printf("%d ", current);
        visited[current] = true;
        queue.insert(queue.end(), adjacencyList[current].begin(), adjacencyList[current].end());
    }
}

void clear(){
    for(int i = 1; i <= numOfVertices; i++){
        visited[i] = false;
    }
    printf("\n");
}
