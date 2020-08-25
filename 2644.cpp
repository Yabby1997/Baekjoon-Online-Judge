#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int numberOfVertices, numberOfEdges, vertexFrom, vertexTo;
bool matrix[101][101] = {false, };
int shortestDistance[101];

void input();
void BFS();
void solve();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    fill_n(shortestDistance, 101, 1000);
    scanf("%d", &numberOfVertices);
    scanf("%d %d", &vertexFrom, &vertexTo);
    scanf("%d", &numberOfEdges);
    for(int i = 0; i < numberOfEdges; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        matrix[from][to] = matrix[to][from] = true;
    }
}

void BFS(){
    int currentDistance = 0;
    queue<int> tempQueue;
    tempQueue.push(vertexFrom);
    shortestDistance[vertexFrom] = currentDistance;
    while(!tempQueue.empty()){
        int vertex = tempQueue.front();
        currentDistance = shortestDistance[vertex];
        tempQueue.pop();
        for(int i = 1; i <= numberOfVertices; i++){
            if(matrix[vertex][i] && currentDistance + 1 < shortestDistance[i]){
                tempQueue.push(i);
                shortestDistance[i] = currentDistance + 1;
            }
        }
    }
}

void solve(){
    BFS();
    printf("%d\n", shortestDistance[vertexTo] == 1000 ? -1 : shortestDistance[vertexTo]);
}

