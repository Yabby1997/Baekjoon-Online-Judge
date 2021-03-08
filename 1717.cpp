#include<vector>
#include<stdio.h>

using namespace std;

int numOfVertices, numOfInputs;
vector<int> group;

void input();
void solve();
int find(int a);
void merge(int a, int b);
void test(int a, int b);

int main() {
    input();
    solve();
    return 0;
}

void input() {
    scanf("%d %d", &numOfVertices, &numOfInputs);
    for(int i = 0; i <= numOfVertices; i++) {
        group.push_back(i);
    }
}

void solve() {
    for(int i = 0; i < numOfInputs; i++) {
        int command, from, to;
        scanf("%d %d %d", &command,  &from, &to);
        
        if(command == 0) {
            merge(from, to);
        } else if(command == 1) {
            test(from, to);
        }
    }
}

int find(int a) {
    if(group[a] == a) {
        return a;
    } else {
        return group[a] = find(group[a]);
    }
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);
    
    if(A != B) {
        if(B < A)
            group[A] = B;
        else
            group[B] = A;
    }
}

void test(int a, int b) {
    int A = find(a);
    int B = find(b);
    
    if(A == B)
        printf("YES\n");
    else
        printf("NO\n");
}

