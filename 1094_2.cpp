#include<stdio.h>

using namespace std;

int main() {
    int count = 0;
    int input = 0;
    
    scanf("%d", &input);
    
    while(input) {
        count += input & 1;
        input = input>>1;
    }

    printf("%d\n", count);
    
    return 0;
}
