#include<stdio.h>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int numOfVertices, numOfEdges, partyVenue;
vector<int> fromPartyDistances, toPartyDistances;
vector<pair<int, int>> fromParty[1001];
vector<pair<int, int>> toParty[1001];
priority_queue<pair<int, int>> tempQueue;

void input();
vector<int> dijkstra(vector<pair<int, int>> paths[1001]);
void showResults();

int main(){
    input();
    fromPartyDistances = dijkstra(fromParty);
    toPartyDistances = dijkstra(toParty);
    showResults();
    return 0;
}

void input(){
    scanf("%d %d %d", &numOfVertices, &numOfEdges, &partyVenue);
    for(int i = 0; i < numOfEdges; i++){
        int from, to, distance;
        scanf("%d %d %d", &from, &to, &distance);
        fromParty[from].push_back({-distance, to});
        toParty[to].push_back({-distance, from});
    }
}

vector<int> dijkstra(vector<pair<int, int>> paths[1001]){
    tempQueue.push({0, partyVenue});
    vector<int> distances(numOfVertices + 1, INT_MAX);
    distances[partyVenue] = 0;
    while(!tempQueue.empty()){
        int distance = -tempQueue.top().first;
        int from = tempQueue.top().second;
        tempQueue.pop();
        if(distances[from] < distance)
            continue;
        for(auto path : paths[from]){
            int newDistance = distance - path.first;
            int to = path.second;
            if(distances[to] > newDistance){
                distances[to] = newDistance;
                tempQueue.push({-newDistance, to});
            }
        }
    }
    return distances;
}

void showResults(){
    int currentWorst = 0;
    for(int i = 1; i <= numOfVertices; i++){
        if(currentWorst < fromPartyDistances[i] + toPartyDistances[i])
            currentWorst = fromPartyDistances[i] + toPartyDistances[i];
    }
    printf("%d\n", currentWorst);
}
