#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> adjacencyList(1001, vector<int>());
vector<bool> visited(1001, false);

void DFS(int currentPosition){
	visited[currentPosition] = true;
	cout<<currentPosition<<" ";
	for(auto i : adjacencyList[currentPosition]){
		if(visited[i] != true){
			DFS(i);
		}
	}
}

void BFS(int currentPosition){
	queue<int> nextVertex;
	nextVertex.push(currentPosition);
	visited[currentPosition] = true;

	while(!nextVertex.empty()){
		int current = nextVertex.front();
		nextVertex.pop();
		cout<<current<<" ";
		for(auto i : adjacencyList[current]){
			if(visited[i] != true){
				visited[i] = true;
				nextVertex.push(i);
			}
		}
	}
}

int main(){
	int numOfVertex = 0;
	int numOfEdge = 0;
	int startingVertex = 0;

	cin>>numOfVertex>>numOfEdge>>startingVertex;
	visited[0] = true;

	for(int i = 0; i < numOfEdge; i++){
		int vertexI = 0;
		int vertexJ = 0;
		cin>>vertexI>>vertexJ;
		adjacencyList[vertexI].push_back(vertexJ);
		adjacencyList[vertexJ].push_back(vertexI);
	}
	
	for(int i = 1; i < numOfVertex + 1; i++){
		sort(adjacencyList[i].begin(), adjacencyList[i].end());
	}
	
	DFS(startingVertex);
	cout<<endl;

	for(int i = 0; i < 1001; i++){
		visited[i] = false;
	}

	BFS(startingVertex);
	cout<<endl;

	return 0;
}