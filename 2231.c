#include<stdio.h>

int main(){
    int inputNum;
    int result = 0;
    
    scanf("%d", &inputNum);
    
    for(int i = 0; i < inputNum; i++){
        int a, b, c, d, e, f, g;
        a = i / 1000000;
        b = (i - a * 1000000) / 100000;
        c = (i - a * 1000000 - b * 100000) / 10000;
        d = (i - a * 1000000 - b * 100000 - c * 10000) / 1000;
        e = (i - a * 1000000 - b * 100000 - c * 10000 - d * 1000) / 100;
        f = (i - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100) / 10;
        g = i - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10;
        if((i + a + b + c + d + e + f + g) == inputNum){
            result = i;
            break;
        }
    }
    printf("%d", result);
    return 0;
}
