#include<stdio.h>
#include<vector>
#include<cmath>

#define left(a) a*2+1
#define right(a) a*2+2
#define MOD 1000000007

using namespace std;

int numOfNumbers, numOfUpdates, numOfOperations;
vector<long long> numbers = {0};
vector<long long> segmentTree;

void input();
long long initTree(int from, int to, int node);
void solve();
long long update(int target, long long newValue, int from, int to, int node);
long long mul(int rangeFrom, int rangeTo, int from, int to, int node);

int main() {
    input();
    segmentTree = vector<long long>((1 << int(ceil(log2(numOfNumbers)) + 1)) - 1, 0);
    initTree(1, numOfNumbers, 0);
    solve();
    return 0;
}

void input() {
    scanf("%d %d %d", &numOfNumbers, &numOfUpdates, &numOfOperations);
    
    for(int i = 0; i < numOfNumbers; i++) {
        long long num;
        scanf("%lld", &num);
        numbers.push_back(num);
    }
}

long long initTree(int from, int to, int node) {
    if(from == to) {
        segmentTree[node] = numbers[from];
    } else {
        int mid = (from + to) / 2;
        long long left = initTree(from, mid, left(node));
        long long right = initTree(mid + 1, to, right(node));
        segmentTree[node] = (left * right) % MOD;
    }
    return segmentTree[node];
}

void solve() {
    for(int i = 0; i < numOfUpdates + numOfOperations; i++) {
        int command, a;
        long long b;
        scanf("%d %d %lld", &command, &a, &b);
        
        if(command == 1) {
            update(a, b, 1, numOfNumbers, 0);
        } else if(command == 2) {
            printf("%lld\n", mul(a, int(b), 1, numOfNumbers, 0));
        }
    }
}

long long mul(int rangeFrom, int rangeTo, int from, int to, int node) {
    if(from > rangeTo || to < rangeFrom) {
        return 1;
    } else if(rangeFrom <= from && to <= rangeTo) {
        return segmentTree[node];
    } else {
        int mid = (from + to) / 2;
        long long left = mul(rangeFrom, rangeTo, from, mid, left(node));
        long long right = mul(rangeFrom, rangeTo, mid + 1, to, right(node));
        return (left * right) % MOD;
    }
}

long long update(int target, long long newValue, int from, int to, int node) {
    if(from == to) {
        if(from == target) {
            segmentTree[node] = newValue;
            numbers[target] = newValue;
        }
        return segmentTree[node];
    } else if(from <= target && target <= to) {
        int mid = (from + to) / 2;
        long long left = update(target, newValue, from, mid, left(node));
        long long right = update(target, newValue, mid + 1, to, right(node));
        segmentTree[node] = (left * right) % MOD;
        return segmentTree[node];
    } else {
        return segmentTree[node];
    }
}

