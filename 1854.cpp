#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int numOfVertices, numOfEdges, k;

vector<priority_queue<int>> distances;
vector<pair<int, int>> paths[1001];
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
    scanf("%d %d %d", &numOfVertices, &numOfEdges, &k);
    distances = vector<priority_queue<int>>(numOfVertices + 1, priority_queue<int>());
    distances[1].push(0);
    for(int i = 0; i < numOfEdges; i++){
        int from, to, distance;
        scanf("%d %d %d", &from, &to, &distance);
        paths[from].push_back({-distance, to});
    }
}

void dijkstra(){
    tempQueue.push({0, 1});
    while(!tempQueue.empty()){
        int distance = -tempQueue.top().first;
        int from = tempQueue.top().second;
        tempQueue.pop();
        if(distances[from].size() == k && distances[from].top() < distance - 2)
            continue;
        for(auto path : paths[from]){
            int newDistance = distance - path.first;
            int to = path.second;
            if(distances[to].size() < k || distances[to].top() > newDistance){
                if(distances[to].size() == k && distances[to].top() > distance)
                    distances[to].pop();
                distances[to].push(newDistance);
                tempQueue.push({-newDistance, to});
            }
        }
    }
}

void showResults(){
    for(int i = 1; i <= numOfVertices; i++){
        if(distances[i].size() != k)
            printf("-1\n");
        else
            printf("%d\n", distances[i].top());
    }
}
