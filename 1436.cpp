#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool examine(int examiningNum){                                             //to_string CONVERTS INT TO STRING
    return to_string(examiningNum).find("666") != -1;                     //18446744073709551615 == -1 IT MEANS IT DOESN'T EXIST IN GIVEN STRING
}

int main(void){
    int ithFilm;
    int i = 0;
    int tripleSix = 666;
    cin>>ithFilm;
    while(i < ithFilm){
        if(examine(tripleSix++))
            i++;
    }
    cout<<tripleSix - 1<<endl;
    
    return 0;
}
