#include<stdio.h>
#include<queue>

using namespace std;

int numOfComputers, numOfConnections;
bool matrix[101][101] = {false, };
bool visited[101] = {false, };

void input();
void BFS(int startingVertex);

int main(){
    input();
    BFS(1);
    return 0;
}

void BFS(int startingVertex){
    int counter = 0;
    queue<int> tempQueue;
    tempQueue.push(startingVertex);
    visited[startingVertex] = true;
    while(!tempQueue.empty()){
        int vertex = tempQueue.front();
        tempQueue.pop();
        for(int i = 1; i <= numOfComputers; i++){
            if(matrix[vertex][i] && !visited[i]){
                tempQueue.push(i);
                visited[i] = true;
                counter++;
            }
        }
    }
    printf("%d\n", counter);
}

void input(){
    scanf("%d", &numOfComputers);
    scanf("%d", &numOfConnections);
    for(int i = 0; i < numOfConnections; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        matrix[from][to] = matrix[to][from] = true;
    }
}

