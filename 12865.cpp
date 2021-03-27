#include<stdio.h>
#include<vector>

using namespace std;

int numOfItems, maximumWeight;
vector<int> weightValueArray, copyOfWeightValueArray;
int best = 0;

int main() {
    scanf("%d %d", &numOfItems, &maximumWeight);
    weightValueArray = vector<int>(maximumWeight + 1, 0);
    copyOfWeightValueArray = weightValueArray;
    
    for(int i = 0; i < numOfItems; i++) {
        int weight, value;
        scanf("%d %d", &weight, &value);
        
        for(int j = 0; j <= maximumWeight; j++) {
            int newWeight = j + weight;
            
            if(j + weight > maximumWeight) {
                break;
            }
            
            int newValue = weightValueArray[j] + value;
            
            if(copyOfWeightValueArray[newWeight] < newValue) {
                copyOfWeightValueArray[newWeight] = newValue;
                if(best < newValue) {
                    best = newValue;
                }
            }
        }
        weightValueArray = copyOfWeightValueArray;
    }
    
    printf("%d\n", best);
    
    return 0;
}

