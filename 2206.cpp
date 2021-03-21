#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int INF = 200000000, height, width, currentRow, currentCol;
bool breakable;
vector<vector<int>> matrix, brokenMatrix;
vector<int> xDirection = {-1, 1, 0, 0};
vector<int> yDirection = {0, 0, -1, 1};
queue<tuple<int, int, bool>> visitingQueue;

void BFS();

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>height>>width;
    
    for(int i = 0; i < height; i++) {
        vector<int> eachRow;
        string input;
        cin>>input;
        for(int j = 0; j < width; j++) {
            eachRow.push_back(input[j] - '0' == 1 ? -1 : INF);
        }
        matrix.push_back(eachRow);
    }
    
    matrix[0][0] = 1;
    brokenMatrix = matrix;
    
    visitingQueue.emplace(0, 0, true);
    BFS();
    
    int resultUnbroken = matrix[height - 1][width - 1];
    int resultBroken = brokenMatrix[height - 1][width - 1];
    
    if(resultUnbroken == resultBroken && resultUnbroken == INF)
        cout<<-1<<endl;
    else if(resultUnbroken <= resultBroken)
        cout<<resultUnbroken<<endl;
    else if(resultUnbroken > resultBroken)
        cout<<resultBroken<<endl;
    
    return 0;
}

void BFS() {
    while(!visitingQueue.empty()) {
        tie(currentRow, currentCol, breakable) = visitingQueue.front();
        visitingQueue.pop();
        
        for(int i = 0; i < 4; i++) {
            int nextRow = currentRow + yDirection[i];
            int nextCol = currentCol + xDirection[i];
            
            if(nextRow < 0 || nextRow >= height || nextCol < 0 || nextCol >= width) {
                continue;
            }
            
            if(breakable){
                if(matrix[nextRow][nextCol] == -1) {
                    brokenMatrix[nextRow][nextCol] = matrix[currentRow][currentCol] + 1;
                    visitingQueue.emplace(nextRow, nextCol, false);
                }
                else if(matrix[currentRow][currentCol] + 1 < matrix[nextRow][nextCol]) {
                    matrix[nextRow][nextCol] = matrix[currentRow][currentCol] + 1;
                    visitingQueue.emplace(nextRow, nextCol, true);
                }
            }
            else if(brokenMatrix[currentRow][currentCol] + 1 < brokenMatrix[nextRow][nextCol]) {
                brokenMatrix[nextRow][nextCol] = brokenMatrix[currentRow][currentCol] + 1;
                visitingQueue.emplace(nextRow, nextCol, false);
            }
        }
    }
}

