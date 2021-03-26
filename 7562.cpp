#include<stdio.h>
#include<vector>
#include<queue>

#define INF 200000000

using namespace std;

int numOfTests, width;
int startingRow, startingCol, destinationRow, destinationCol;
vector<vector<int>> board;
queue<pair<int, int>> cellQueue;

vector<int> rowDirection = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> colDirection = {1, -1, 1, -1, 2, -2, 2, -2};

void BFS();

int main() {
    scanf("%d", &numOfTests);
    
    for(int i = 0; i < numOfTests; i++) {
        scanf("%d", &width);
        board = vector<vector<int>>(width, vector<int>(width, INF));
        
        scanf("%d %d", &startingRow, &startingCol);
        scanf("%d %d", &destinationRow, &destinationCol);
        
        board[startingRow][startingCol] = 0;
        cellQueue.push(make_pair(startingRow, startingCol));
        
        BFS();
        
        printf("%d\n", board[destinationRow][destinationCol]);
    }
    return 0;
}

void BFS() {
    while(!cellQueue.empty()) {
        int currentRow = cellQueue.front().first;
        int currentCol = cellQueue.front().second;
        int turns = board[currentRow][currentCol];
        cellQueue.pop();
        
        for(int i = 0; i < 8; i++) {
            int nextRow = currentRow + rowDirection[i];
            int nextCol = currentCol + colDirection[i];
            
            if(nextRow < 0 || nextRow >= width || nextCol < 0 || nextCol >= width) {
                continue;
            }
            
            if(board[nextRow][nextCol] > turns + 1) {
                board[nextRow][nextCol] = turns + 1;
                cellQueue.push(make_pair(nextRow, nextCol));
            }
        }
    }
}

