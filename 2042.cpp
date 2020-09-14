#include <iostream>
#include <vector>
#include <cmath>

#define leftChild(parentNode) parentNode * 2
#define rightChild(parentNode) parentNode * 2 + 1

using namespace std;

vector<long long> segmentTree;
vector<long long> numbers = {-1, };

int numOfNumbers, numOfChanges, numOfCalculations, lengthOfTree;

void input();
void solve();
long long initTreeNode(int node, int from, int to);
long long sum(int node, int from, int to, int left, int right);
void updateTree(int node, int from, int to, int index, long long diff);

int main(){
    input();
    solve();
    return 0;
}

void input(){
    scanf("%d %d %d", &numOfNumbers, &numOfChanges, &numOfCalculations);
    lengthOfTree = 1 << ((int)ceil(log2(numOfNumbers)) + 1);
    segmentTree = vector<long long>(lengthOfTree, 0);
    for(int i = 0; i < numOfNumbers; i++){
        long long number;
        scanf("%lld", &number);
        numbers.push_back(number);
    }
    initTreeNode(1, 1, numOfNumbers);
}

void solve(){
    while(numOfChanges != 0 || numOfCalculations != 0){
        int command;
        scanf("%d", &command);
        if(command == 1 && numOfChanges != 0){
            int index;
            long long value;
            scanf("%d %lld", &index, &value);
            updateTree(1, 1, numOfNumbers, index, value - numbers[index]);
            numOfChanges--;
        }
        else if(command == 2 && numOfCalculations != 0){
            int from, to;
            scanf("%d %d", &from, &to);
            printf("%lld\n", sum(1, 1, numOfNumbers, from, to));
            numOfCalculations--;
        }
    }
}

long long initTreeNode(int node, int from, int to){
    if (from == to)
        segmentTree[node] = numbers[from];
    else{
        int mid = (from + to) / 2;
        segmentTree[node] = initTreeNode(leftChild(node), from, mid) + initTreeNode(rightChild(node), mid + 1, to);
    }
    return segmentTree[node];
}

void updateTree(int node, int from, int to, int index, long long diff){
    if (index < from || index > to)
        return;
    
    segmentTree[node] += diff;
    if (from != to){
        int mid = (from + to) / 2;
        updateTree(leftChild(node), from, mid, index, diff);
        updateTree(rightChild(node), mid+1, to, index, diff);
    }
    else
        numbers[from] += diff;
}

long long sum(int node, int from, int to, int rangeFrom, int rangeTo){
    if (from > rangeTo || to < rangeFrom)
        return 0;
    else if (from >= rangeFrom && to <= rangeTo)
        return segmentTree[node];
    else {
        int mid = (from + to) / 2;
        return sum(leftChild(node), from, mid, rangeFrom, rangeTo) + sum(rightChild(node), mid+1, to, rangeFrom, rangeTo);
    }
}

