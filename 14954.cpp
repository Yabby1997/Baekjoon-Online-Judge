#include<iostream>
#include<string>

using namespace std;

long beHappy(string n){
    long tempLong = 0;
    int temp;
    for(string::iterator i = n.begin(); i < n.end(); i++){
        temp = (*i) - '0';
        tempLong = tempLong + (temp * temp);
    }
    //cout<<"@DEBUG@ "<<tempLong<<endl;
    if(tempLong == 1){
        cout<<"HAPPY"<<endl;
    }
    else if(tempLong != 4){
        beHappy(to_string(tempLong));
    }
    else{
        cout<<"UNHAPPY"<<endl;
    }
}

int main(void){
    string temp;
    cin>>temp;
    beHappy(temp);
    return 0;
}


