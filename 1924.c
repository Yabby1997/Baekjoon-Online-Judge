#include<stdio.h>

int calcDaysFeb();
int calcDaysMar();
int calcDaysApr();
int calcDaysMay();
int calcDaysJun();
int calcDaysJul();
int calcDaysAug();
int calcDaysSep();
int calcDaysOct();
int calcDaysNov();
int calcDaysDec();

int main(){
    int month, date, days = 0;
    scanf("%d %d", &month, &date);

    switch(month){
        case 1:
            days = date;
            break;
        case 2:
            days = date + calcDaysFeb();
            break;
        case 3:
            days = date + calcDaysMar();
            break;
        case 4:
            days = date + calcDaysApr();
            break;
        case 5:
            days = date + calcDaysMay();
            break;
        case 6:
            days = date + calcDaysJun();
            break;
        case 7:
            days = date + calcDaysJul();
            break;
        case 8:
            days = date + calcDaysAug();
            break;
        case 9:
            days = date + calcDaysSep();
            break;
        case 10:
            days = date + calcDaysOct();
            break;
        case 11:
            days = date + calcDaysNov();
            break;
        case 12:
            days = date + calcDaysDec();
            break;            
    }
    
    switch(days % 7){
        case 1:
            printf("MON");
            break;
        case 2:
            printf("TUE");
            break;
        case 3:
            printf("WED");
            break;
        case 4:
            printf("THU");
            break;
        case 5:
            printf("FRI");
            break;
        case 6:
            printf("SAT");
            break;
        case 0:
            printf("SUN");
            break;
    }
    return 0;
}

int calcDaysFeb(){
    return 31;
}

int calcDaysMar(){
    return calcDaysFeb() + 28;
}

int calcDaysApr(){
    return calcDaysMar() + 31;
}

int calcDaysMay(){
    return calcDaysApr() + 30;
}

int calcDaysJun(){
    return calcDaysMay() + 31;
}

int calcDaysJul(){
    return calcDaysJun() + 30;
}

int calcDaysAug(){
    return calcDaysJul() + 31;
}

int calcDaysSep(){
    return calcDaysAug() + 31;
}

int calcDaysOct(){
    return calcDaysSep() + 30;
}

int calcDaysNov(){
    return calcDaysOct() + 31;
}

int calcDaysDec(){
    return calcDaysNov() + 30;
}
    // 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.
