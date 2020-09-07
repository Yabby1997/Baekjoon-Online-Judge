#include<stdio.h>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>

using namespace std;

int numOfVertices, numOfEdges, numOfIncrements, startingVertex, destinationVertex;
vector<vector<int>> costs;
list<int> incrementingCosts;
vector<pair<int, int>> paths[1001];
priority_queue<pair<pair<int, int>, int>> tempQueue;

void input();
void solve();
void dijkstra();
void incrementCost(int increasingCost);
void showResult();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    scanf("%d %d %d", &numOfVertices, &numOfEdges, &numOfIncrements);
    scanf("%d %d", &startingVertex, &destinationVertex);
    for(int i = 0; i < numOfEdges; i++){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        paths[from].push_back({-cost, to});
        paths[to].push_back({-cost, from});
    }
    for(int i = 0; i < numOfIncrements; i++){
        int incrementingCost;
        scanf("%d", &incrementingCost);
        incrementingCosts.push_back(incrementingCost);
    }
}

void solve(){
    dijkstra();
    while(!incrementingCosts.empty()){
        incrementCost(incrementingCosts.front());
        incrementingCosts.pop_front();
    }
}

void dijkstra(){
    for(int i = 0; i <= numOfVertices; i++)
        costs.push_back(vector<int>(numOfVertices, INT_MAX));
    tempQueue.push({{0, startingVertex}, 0});
    costs[startingVertex][0] = 0;
    while(!tempQueue.empty()){
        int currentCost = -tempQueue.top().first.first;
        int from = tempQueue.top().first.second;
        int currentStep = tempQueue.top().second;
        tempQueue.pop();
        if(currentStep < costs[from].size() && costs[from][currentStep] < currentCost)
            continue;
        for(auto path : paths[from]){
            int potentialCost = currentCost - path.first;
            int to = path.second;
            if(currentStep + 1 < costs[to].size() && potentialCost < costs[to][currentStep + 1]){
                costs[to][currentStep + 1] = potentialCost;
                tempQueue.push({{-potentialCost, to}, currentStep + 1});
            }
        }
    }
    showResult();
}

void incrementCost(int increasingCost){
    for(int i = 1; i < costs[destinationVertex].size(); i++){
        if(costs[destinationVertex][i] != INT_MAX)
            costs[destinationVertex][i] += increasingCost * i;
    }
    showResult();
}

void showResult(){
    int minimum = INT_MAX;
    for(int i = 0; i < costs[destinationVertex].size(); i++){
        if(costs[destinationVertex][i] < minimum)
            minimum = costs[destinationVertex][i];
    }
    printf("%d\n", minimum);
}

