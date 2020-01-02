#include<stdio.h>
#include<math.h>

int main(){
    int numOfCases;
    double height, width, visitors;
    scanf("%d", &numOfCases);
    for(int i = 0; i < numOfCases; i++){
        scanf("%lf %lf %lf", &height, &width, &visitors);
        int hh = (int)visitors % (int)height;
        int ww = (int)ceil(visitors / height);
        if(hh == 0)
            hh = height;
        if(ww < 10)
            printf("%d0%d\n", hh, ww);
        else
            printf("%d%d\n", hh, ww);
    }
    return 0;
}
