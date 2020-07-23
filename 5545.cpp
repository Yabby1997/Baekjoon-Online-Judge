#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int numOfToppings, costOfToppings, cost, cal;
float overallCPW;
vector<int> calOfToppings;

float calcCPW(int cal, int cost);

int main(){
    scanf("%d", &numOfToppings);
    scanf("%d %d", &cost, &costOfToppings);
    scanf("%d", &cal);
    overallCPW = calcCPW(cal, cost);
    
    for(int i = 0; i < numOfToppings; i++){
        int temp;
        scanf("%d", &temp);
        calOfToppings.push_back(temp);
    }
    sort(calOfToppings.begin(), calOfToppings.end(), [](int a, int b){return a > b;});
    
    for(int i = 0; i < numOfToppings; i++){
        float toppingAddedCPW = calcCPW(cal + calOfToppings[i], cost + costOfToppings);
        if(overallCPW < toppingAddedCPW){
            cal += calOfToppings[i];
            cost += costOfToppings;
            overallCPW = toppingAddedCPW;
        }
    }
    cout<<(int)overallCPW<<endl;
    return 0;
}

float calcCPW(int cal, int cost){
    return (float)cal / (float)cost;
}
