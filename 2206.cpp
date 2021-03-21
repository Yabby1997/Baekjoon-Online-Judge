#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int INF = 200000000, height, width;
vector<vector<int>> matrix, brokenMatrix;
vector<int> xDirection = {-1, 1, 0, 0};
vector<int> yDirection = {0, 0, -1, 1};
queue<pair<pair<int, int>, bool>> visitingQueue;

void BFS();
void showMatrix(vector<vector<int>> board);

int main() {
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
    
    visitingQueue.push(make_pair(make_pair(0, 0), true));
    BFS();
    
    int resultUnbroken = matrix[height - 1][width - 1];
    int resultBroken = brokenMatrix[height - 1][width - 1];
    
//    showMatrix(matrix);
//    showMatrix(brokenMatrix);
    
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
        int currentRow = visitingQueue.front().first.first;
        int currentCol = visitingQueue.front().first.second;
        bool breakable = visitingQueue.front().second;
        visitingQueue.pop();
        
        for(int i = 0; i < 4; i++) {
            int nextRow = currentRow + yDirection[i];
            int nextCol = currentCol + xDirection[i];
            
            if(nextRow < 0 || nextRow >= height || nextCol < 0 || nextCol >= width) {
                continue;
            }
            
            // 한번 부술 수 있음
            if(breakable){
                // 벽만났다
                if(matrix[nextRow][nextCol] == -1) {
                    brokenMatrix[nextRow][nextCol] = matrix[currentRow][currentCol] + 1;
                    visitingQueue.push(make_pair(make_pair(nextRow, nextCol), false));
//                    cout<<currentRow<<", "<<currentCol<<" -> "<<nextRow<<", "<<nextCol<<" break the wall. "<<brokenMatrix[nextRow][nextCol]<<endl;
                }
                // 벽 아니야
                else if(matrix[currentRow][currentCol] + 1 < matrix[nextRow][nextCol]) {
                    matrix[nextRow][nextCol] = matrix[currentRow][currentCol] + 1;
                    visitingQueue.push(make_pair(make_pair(nextRow, nextCol), true));
//                    cout<<currentRow<<", "<<currentCol<<" -> "<<nextRow<<", "<<nextCol<<" spread without breaking. "<<matrix[nextRow][nextCol]<<endl;
                }
            }
            // 이제 더 못부숴
            else if(brokenMatrix[currentRow][currentCol] + 1 < brokenMatrix[nextRow][nextCol]) {
                brokenMatrix[nextRow][nextCol] = brokenMatrix[currentRow][currentCol] + 1;
                visitingQueue.push(make_pair(make_pair(nextRow, nextCol), false));
//                cout<<currentRow<<", "<<currentCol<<" -> "<<nextRow<<", "<<nextCol<<" spread with no chance to break more walls. "<<brokenMatrix[nextRow][nextCol]<<endl;
            }
        }
    }
}

void showMatrix(vector<vector<int>> board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            char cell = board[i][j] == INF ? '.' : board[i][j] == -1 ? 'X' : 'O';
            cout<<cell<<" ";
        }
        cout<<endl;
    }
    cout<<"===="<<endl;
}

