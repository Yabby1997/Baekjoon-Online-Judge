#include<stdio.h>

using namespace std;

long long games, wins, winRatio;

void input();
void solve();
long long getRatio(long long wins, long long games);
int binarySearch(int left, int right);

int main(){
    input();
    solve();
    return 0;
}

void input(){
    scanf("%lld %lld", &games, &wins);
    winRatio = getRatio(wins, games);
}

long long getRatio(long long wins, long long games){
    return (wins * 100) / games;
}

void solve(){
    printf("%d\n", winRatio < 99 ? binarySearch(1, 1000000000) : -1);
}

int binarySearch(int left, int right){
    int result = -1;
    while(left <= right){
        int mid = (right + left) / 2;
        long long midRatio = getRatio(wins + mid, games + mid);
        if(midRatio > winRatio){
            right = mid - 1;
            result = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return result;
}
