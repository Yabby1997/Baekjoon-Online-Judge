#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>

#define leftChild(parent) parent * 2
#define rightChild(parent) parent * 2 + 1

using namespace std;

vector<long long> numbers;
vector<int> segmentTree;
int numOfNumbers, lengthOfSegmentTree;
long long best = 0;

void solve();
int initSegmentTreeNode(int node, int from, int to);
int minQuery(int node, int from, int to, int rangeFrom, int rangeTo);
void divideAndConquer(int rangeFrom, int rangeTo);
void resetAll();

int main(){
    solve();
    return 0;
}

void solve(){
    while(true){
        scanf("%d", &numOfNumbers);
        if(!numOfNumbers)
            return;
        numbers.push_back(INT_MAX);
        lengthOfSegmentTree = 1 << (int)(ceil(log2(numOfNumbers)) + 1);
        segmentTree = vector<int>(lengthOfSegmentTree, 0);
        for(int i = 0; i < numOfNumbers; i++){
            long long number;
            scanf("%lld", &number);
            numbers.push_back(number);
        }
        initSegmentTreeNode(1, 1, numOfNumbers);
        divideAndConquer(1, numOfNumbers);
        printf("%lld\n", best);
        resetAll();
    }
}

int initSegmentTreeNode(int node, int from, int to){
    if(from == to){
        segmentTree[node] = from;
    }
    else{
        int mid = (from + to) / 2;
        int left = initSegmentTreeNode(leftChild(node), from, mid);
        int right = initSegmentTreeNode(rightChild(node), mid + 1, to);
        int minIndex = left;
        if(numbers[right] < numbers[minIndex])
            minIndex = right;
        segmentTree[node] = minIndex;
    }
    return segmentTree[node];
}

int minQuery(int node, int from, int to, int rangeFrom, int rangeTo){
    if(rangeFrom > to || rangeTo < from)
        return 0;
    else if(from >= rangeFrom && to <= rangeTo)
        return segmentTree[node];
    else{
        int mid = (from + to) / 2;
        int left = minQuery(leftChild(node), from, mid, rangeFrom, rangeTo);
        int right = minQuery(rightChild(node), mid + 1, to, rangeFrom, rangeTo);
        int minIndex = left;
        if(numbers[right] < numbers[minIndex])
            minIndex = right;
        return minIndex;
    }
}

void divideAndConquer(int rangeFrom, int rangeTo){
    if(rangeFrom > rangeTo)
        return;
    int minIndex = minQuery(1, 1, numOfNumbers, rangeFrom, rangeTo);
    long long currentBest = numbers[minIndex] * (rangeTo - rangeFrom + 1);
    if(best < currentBest)
        best = currentBest;
    divideAndConquer(rangeFrom, minIndex - 1);
    divideAndConquer(minIndex + 1, rangeTo);
}

void resetAll(){
    best = 0;
    numbers.clear();
    segmentTree.clear();
}

