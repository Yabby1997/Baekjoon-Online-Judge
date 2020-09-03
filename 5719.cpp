#include<stdio.h>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

int numOfVertices, numOfEdges, startingVertex, destinationVertex, result;

int distances[500];
vector<int> parentsOfVertices[500];
vector<pair<int, int>> paths[500];
priority_queue<pair<int, int>> tempQueue;
vector<int> results;

bool input();
int dijkstra();
void configurePaths(int to);
void clear();
void showResults();

int main(){
    while(true){
        if(!input())
            break;
        result = dijkstra();
        if(result != INT_MAX){
            configurePaths(destinationVertex);
            result = dijkstra();
        }
        results.push_back(result);
        clear();
    }
    showResults();
    return 0;
}

bool input(){
    scanf("%d %d", &numOfVertices, &numOfEdges);
    if(numOfVertices == 0 && numOfEdges == 0)
        return false;
    scanf("%d %d", &startingVertex, &destinationVertex);
    for(int i = 0; i < numOfEdges; i++){
        int from, to, distance;
        scanf("%d %d %d", &from, &to, &distance);
        paths[from].push_back({-distance, to});
    }
    return true;
}

int dijkstra(){
    fill_n(distances, numOfVertices, INT_MAX);
    distances[startingVertex] = 0;
    tempQueue.push({0, startingVertex});
    while(!tempQueue.empty()){
        int distance = -tempQueue.top().first;
        int from = tempQueue.top().second;
        tempQueue.pop();
        if(distances[from] < distance)
            continue;
        for(auto path : paths[from]){
            if(path.first != -INT_MAX){
                int newDistance = distance - path.first;
                int to = path.second;
                if(newDistance < distances[to]){
                    parentsOfVertices[to].clear();
                    parentsOfVertices[to].push_back(from);
                    distances[to] = newDistance;
                    tempQueue.push({-newDistance, to});
                }
                else if(newDistance == distances[to]){
                    parentsOfVertices[to].push_back(from);
                }
            }
        }
    }
    return distances[destinationVertex];
}

void configurePaths(int to){
    if(!parentsOfVertices[to].empty()){
        int from = parentsOfVertices[to].back();
        parentsOfVertices[to].pop_back();
        for(int i = 0; i < paths[from].size(); i++){
            if(paths[from][i].second == to){
                paths[from][i].first = -INT_MAX;
                break;
            }
        }
        if(from != startingVertex)
            configurePaths(from);
        if(!parentsOfVertices[to].empty())
            configurePaths(to);
    }
    return;
}

void clear(){
    for(int i = 0; i < numOfVertices; i++){
        paths[i] = vector<pair<int, int>>();
        parentsOfVertices[i].clear();
    }
}

void showResults(){
    for(int i = 0; i < results.size(); i++){
        if(results[i] == INT_MAX)
            printf("-1\n");
        else
            printf("%d\n", results[i]);
    }
}

