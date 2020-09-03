#include<stdio.h>
#include<queue>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

int numOfVertices, numOfEdges, startingVertex;
int distances[20001];
vector<pair<int, int>> paths[20001];
priority_queue<pair<int, int>> tempQueue;

void input();
void dijkstra();
void showResults();

int main(){
    input();
    dijkstra();
    showResults();
    return 0;
}

void input(){
    scanf("%d %d", &numOfVertices, &numOfEdges);
    scanf("%d", &startingVertex);
    fill_n(distances, numOfVertices + 1, INT_MAX);
    distances[startingVertex] = 0;
    tempQueue.push({0, startingVertex});
    for(int i = 0; i < numOfEdges; i++){
        int from, to, distance;
        scanf("%d %d %d", &from, &to, &distance);
        paths[from].push_back({-distance, to});
    }
}

void dijkstra(){
    while(!tempQueue.empty()){
        int distance = -tempQueue.top().first;
        int from = tempQueue.top().second;
        tempQueue.pop();
        if(distances[from] < distance)
            continue;
        for(auto path : paths[from]){
            int nextDistance = distance - path.first;
            int to = path.second;
            if(distances[to] > nextDistance){
                distances[to] = nextDistance;
                tempQueue.push({-nextDistance, to});
            }
        }
    }
}

void showResults(){
    for(int i = 1; i <= numOfVertices; i++){
        if(distances[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", distances[i]);
    }
}
