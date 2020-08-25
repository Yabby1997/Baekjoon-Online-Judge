#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int from, to, currentDistance;
int shortestDistance[100001];
queue<int> tempQueue;

void input();
void BFS();
void move(int vertex, int destination);
void showResult();

int main(){
    input();
    BFS();
    showResult();
    return 0;
}

void input(){
    scanf("%d %d", &from, &to);
    fill_n(shortestDistance, 100001, 999999);
}

void BFS(){
    tempQueue.push(from);
    shortestDistance[from] = 0;
    while(!tempQueue.empty()){
        int vertex = tempQueue.front();
        currentDistance = shortestDistance[vertex];
        tempQueue.pop();
        move(vertex, vertex - 1);
        move(vertex, vertex + 1);
        move(vertex, vertex * 2);
    }
}

void move(int vertex, int destination){
    if(destination >= 0 && destination < 100001){
        if(currentDistance + 1 < shortestDistance[destination]){
            tempQueue.push(destination);
            shortestDistance[destination] = currentDistance + 1;
        }
    }
}

void showResult(){
    printf("%d\n", shortestDistance[to]);
}

