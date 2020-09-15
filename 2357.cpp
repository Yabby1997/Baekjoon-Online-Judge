#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>

#define leftChild(parent) parent * 2
#define rightChild(parent) parent * 2 + 1

using namespace std;

int numOfNumbers, numOfQueries, lengthOfTree;
vector<int> minSegmentTree;
vector<int> maxSegmentTree;
vector<int> numbers = {-1};

void inputNumbers();
int initTreeNode(vector<int> *tree, bool isMin, int node, int from, int to);
void solve();
int query(vector<int> *tree, bool isMin, int node, int from, int to, int rangeFrom, int rangeTo);

int main(){
    inputNumbers();
    solve();
    return 0;
}

void inputNumbers(){
    scanf("%d %d", &numOfNumbers, &numOfQueries);
    for(int i = 0; i < numOfNumbers; i++){
        int number;
        scanf("%d", &number);
        numbers.push_back(number);
    }
    lengthOfTree = 1 << ((int)ceil(log2(numOfNumbers)) + 1);
    minSegmentTree = vector<int>(lengthOfTree, 0);
    maxSegmentTree = vector<int>(lengthOfTree, 0);
    initTreeNode(&minSegmentTree, true, 1, 1, numOfNumbers);
    initTreeNode(&maxSegmentTree, false, 1, 1, numOfNumbers);
}

int initTreeNode(vector<int> *tree, bool isMin, int node, int from, int to){
    if(from == to)
        tree->at(node) = numbers[from];
    else{
        int mid = (from + to) / 2;
        int left = initTreeNode(tree, isMin, leftChild(node), from, mid);
        int right = initTreeNode(tree, isMin, rightChild(node), mid + 1, to);
        tree->at(node) = isMin ? min(left, right) : max(left, right);
    }
    return tree->at(node);
}

int query(vector<int> *tree, bool isMin, int node, int from, int to, int rangeFrom, int rangeTo){
    if(rangeFrom > to || rangeTo < from)
        return isMin ? INT_MAX : -INT_MAX;
    else if(from >= rangeFrom && to <= rangeTo)
        return tree->at(node);
    else{
        int mid = (from + to) / 2;
        int left = query(tree, isMin, leftChild(node), from, mid, rangeFrom, rangeTo);
        int right = query(tree, isMin, rightChild(node), mid + 1, to, rangeFrom, rangeTo);
        return isMin ? min(left, right) : max(left, right);
    }
}

void solve(){
    for(int i = 0; i < numOfQueries; i++){
        int rangeFrom, rangeTo, min, max;
        scanf("%d %d", &rangeFrom, &rangeTo);
        min = query(&minSegmentTree, true, 1, 1, numOfNumbers, rangeFrom, rangeTo);
        max = query(&maxSegmentTree, false, 1, 1, numOfNumbers, rangeFrom, rangeTo);
        printf("%d %d\n", min, max);
    }
}

