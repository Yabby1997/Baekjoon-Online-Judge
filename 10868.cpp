#include <stdio.h>
#include <vector>
#include <limits.h>
#include <math.h>

#define leftChild(parent) parent * 2
#define rightChild(parent) parent * 2 + 1

using namespace std;

int numOfNumbers, numOfQueries, lengthOfSegmentTree;
vector<int> numbers = {-1};
vector<int> minSegmentTree;

void input();
void solve();
int initMinSegmentTree(int node, int from, int to);
int minQuery(int node, int from, int to, int rangeFrom, int rangeTo);

int main(){
    input();
    solve();
    return 0;
}

void input(){
    scanf("%d %d", &numOfNumbers, &numOfQueries);
    lengthOfSegmentTree = 1 << int(ceil(log2(numOfNumbers)) + 1);
    minSegmentTree = vector<int>(lengthOfSegmentTree, 0);
    for(int i = 0; i < numOfNumbers; i++){
        int number;
        scanf("%d", &number);
        numbers.push_back(number);
    }
    initMinSegmentTree(1, 1, numOfNumbers);
}

void solve(){
    for(int i = 0; i < numOfQueries; i++){
        int rangeFrom, rangeTo;
        scanf("%d %d", &rangeFrom, &rangeTo);
        printf("%d\n", minQuery(1, 1, numOfNumbers, rangeFrom, rangeTo));
    }
}

int initMinSegmentTree(int node, int from, int to){
    if(from == to)
        minSegmentTree[node] = numbers[from];
    else{
        int mid = (from + to) / 2;
        int leftMin = initMinSegmentTree(leftChild(node), from, mid);
        int rightMin = initMinSegmentTree(rightChild(node), mid + 1, to);
        minSegmentTree[node] = leftMin < rightMin ? leftMin : rightMin;
    }
    return minSegmentTree[node];
}

int minQuery(int node, int from, int to, int rangeFrom, int rangeTo){
    if(rangeFrom > to || rangeTo < from)
        return INT_MAX;
    else if(from >= rangeFrom && to <= rangeTo)
        return minSegmentTree[node];
    else{
        int mid = (from + to) / 2;
        int leftMin = minQuery(leftChild(node), from, mid, rangeFrom, rangeTo);
        int rightMin = minQuery(rightChild(node), mid + 1, to, rangeFrom, rangeTo);
        return leftMin < rightMin ? leftMin : rightMin;
    }
}

