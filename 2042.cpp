#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> tree;
vector<long long> numbers;

int numOfNumbers, numOfChanges, numOfCalculations, lengthOfTree;

void inputNumbers();
void solve();
long long init(int node, int start, int end);
long long sum(int node, int start, int end, int left, int right);
void update(int targetIndex, int node, int start, int end, long long diff);
int leftChild(int parent);
int rightChild(int parent);
void showTree();

int main(){
    inputNumbers();
    solve();
    return 0;
}

void inputNumbers(){
    scanf("%d %d %d", &numOfNumbers, &numOfChanges, &numOfCalculations);
    lengthOfTree = 1<<((int)ceil(log2(numOfNumbers)) + 1);
    tree = vector<long long>(lengthOfTree, 0);
    for(int i = 0; i < numOfNumbers; i++){
        long long number;
        scanf("%lld", &number);
        numbers.push_back(number);
    }
    init(1, 0, numOfNumbers-1);
}

long long init(int node, int start, int end){
    if (start == end)
        tree[node] = numbers[start];
    else{
        int mid = (start + end) / 2;
        tree[node] = init(leftChild(node), start, mid) + init(rightChild(node), mid + 1, end);
    }
    return tree[node];
}

void solve(){
    while(numOfChanges != 0 || numOfCalculations != 0){
        int command, a;
        long long b;
        scanf("%d %d %lld", &command, &a, &b);
        if(command == 1 && numOfChanges != 0){
            update(a - 1, 1, 0, numOfNumbers - 1, b - numbers[a - 1]);
            numOfChanges--;
        }
        else if(command == 2 && numOfCalculations != 0){
            printf("%lld\n", sum(1, 0, numOfNumbers - 1, a - 1, (int)(b - 1)));
            numOfCalculations--;
        }
    }
}

void update(int targetIndex, int node, int start, int end, long long diff){
    if (targetIndex < start || targetIndex > end)
        return;
    
    tree[node] += diff;
    
    if (start != end){
        int mid = (start+end) / 2;
        update(targetIndex, leftChild(node), start, mid, diff);
        update(targetIndex, rightChild(node), mid+1, end, diff);
    }
    //원본값을 수정해주지 않으면 다음 계산에서 오류가 발생한다.
    else if(start == end){
        numbers[start] += diff;
    }
}

long long sum(int node, int start, int end, int left, int right){
    if (start > right || end < left)
        return 0;
    else if (start >= left && end <= right)
        return tree[node];
    else {
        int mid = (start+end) / 2;
        return sum(leftChild(node), start, mid, left, right) + sum(rightChild(node), mid+1, end, left, right);
    }
}

int leftChild(int parent){
    return parent * 2;
}

int rightChild(int parent){
    return parent * 2 + 1;
}

