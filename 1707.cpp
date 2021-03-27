#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> colors;
vector<vector<int>> adjacencyList;
queue<int> edgeQueue;

int numOfTests, numOfVertices, numOfEdges, from, to;

void BFS();
void isValid();

int main() {
    scanf("%d", &numOfTests);
    for(int i = 0; i < numOfTests; i++) {
        scanf("%d %d", &numOfVertices, &numOfEdges);
        adjacencyList = vector<vector<int>>(numOfVertices + 1, vector<int>());
        colors = vector<int>(numOfVertices + 1, 0);
        
        for(int j = 0; j < numOfEdges; j++) {
            scanf("%d %d", &from, &to);
            adjacencyList[from].push_back(to);
            adjacencyList[to].push_back(from);
        }
        
        for(int j = 1; j <= numOfVertices; j++) {
            if(colors[j] == 0) {
                colors[j] = 1;
                edgeQueue.push(j);
                BFS();
            }
        }
        isValid();
    }
    return 0;
}

void BFS(){
    while(!edgeQueue.empty()) {
        int currentFrom = edgeQueue.front();
        int currentColor = colors[currentFrom];
        edgeQueue.pop();
        
        for(int i = 0; i < adjacencyList[currentFrom].size(); i++) {
            int currentTo = adjacencyList[currentFrom][i];
            
            if(colors[currentTo] == 0) {
                colors[currentTo] = -1 * currentColor;
                edgeQueue.push(currentTo);
            }
        }
    }
}

void isValid() {
    for(int i = 1; i <= numOfVertices; i++) {
        for(int j = 0; j < adjacencyList[i].size(); j++) {
            int from = i;
            int to = adjacencyList[i][j];
            if(colors[from] == colors[to]) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    return;
}
