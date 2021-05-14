#include<stdio.h>

using namespace std;

int main() {
    int input = 0;
    scanf("%d", &input);
    input = input & ~(0xFFFFFFFF << 6);
    
    int count = 0;
    while(input != 0) {
        input = input & (input - 1);
        count++;
    }

    printf("%d\n", count == 0 ? 1 : count);
    
    return 0;
}
