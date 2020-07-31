#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dwarfs;

int main(){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int temp;
        scanf("%d", &temp);
        dwarfs.push_back(temp);
        sum += temp;
    }
    
    sort(dwarfs.begin(), dwarfs.end());
    
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if((sum - dwarfs[i] - dwarfs[j]) == 100){
                dwarfs.erase(dwarfs.begin() + i, dwarfs.begin() + i + 1);
                dwarfs.erase(dwarfs.begin() + j - 1, dwarfs.begin() + j);
                i = 10;
                break;
            }
        }
    }
    for(int i = 0; i < dwarfs.size(); i++){
        cout<<dwarfs[i]<<endl;
    }
    
    return 0;
}

