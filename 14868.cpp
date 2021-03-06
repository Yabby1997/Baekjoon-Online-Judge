#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

void input();
void spreadBFS();
void mergeBFS();
void showMap();
int find(int civ);
void merge(int civA, int civB);

int width = 0, numOfCivs = 0, years = 0, remaining = 0;
vector<int> xDirection = {-1, 1, 0, 0};
vector<int> yDirection = {0, 0, -1, 1};
vector<int> actualCiv;
queue<pair<int, int>> mergeQueue;
queue<pair<int, int>> spreadQueue;
vector<vector<int>> map(2001, vector<int>(2001, -1));

int main() {
    input();
    while(true) {
        mergeBFS();
        if(remaining == 1) {
            break;
        }
        spreadBFS();
        years += 1;
        printf("%d %d\n", remaining, years);
    }
    printf("%d\n", years);
    return 0;
}

void input() {
    scanf("%d %d", &width, &numOfCivs);
    remaining = numOfCivs;
    for(int i = 0; i < numOfCivs; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        mergeQueue.push(make_pair(x, y));
        map[x][y] = i;
        actualCiv.push_back(i);
    }
}

void mergeBFS() {
    while(!mergeQueue.empty()) {
        int currentX = mergeQueue.front().first;
        int currentY = mergeQueue.front().second;
        mergeQueue.pop();
        int currentCiv = map[currentX][currentY];
        spreadQueue.push(make_pair(currentX, currentY));
        
        for(int i = 0; i < 4; i++) {
            int nextX = currentX + xDirection[i];
            int nextY = currentY + yDirection[i];
            
            if(nextX < 1 || nextX > width || nextY < 1 || nextY > width)
                continue;
            
            int nextCiv = map[nextX][nextY];
            if(nextCiv == -1 || find(currentCiv) == find(nextCiv))
                continue;
            
            merge(currentCiv, nextCiv);
        }
    }
}

void spreadBFS() {
    while(!spreadQueue.empty()) {
        int currentX = spreadQueue.front().first;
        int currentY = spreadQueue.front().second;
        spreadQueue.pop();
        int currentCiv = map[currentX][currentY];
        
        for(int i = 0; i < 4; i++) {
            int nextX = currentX + xDirection[i];
            int nextY = currentY + yDirection[i];
            
            if(nextX < 1 || nextX > width || nextY < 1 || nextY > width)
                continue;
            
            if(map[nextX][nextY] == -1){
                map[nextX][nextY] = currentCiv;
                mergeQueue.push(make_pair(nextX, nextY));
            }
        }
    }
}

int find(int civ) {
    if(actualCiv[civ] == civ) {
        return civ;
    } else {
        return find(actualCiv[civ]);
    }
}

void merge(int civA, int civB) {
    int actualA = find(civA);
    int actualB = find(civB);
    
    actualCiv[actualB] = actualA;
    remaining -= 1;
}


