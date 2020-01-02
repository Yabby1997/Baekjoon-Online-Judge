import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        int isLeapYear = 0;
        if(year % 400 == 0)
            isLeapYear = 1;
        else if(year % 100 == 0)
            isLeapYear = 0;
        else if(year % 4 == 0)
            isLeapYear = 1;
        else
            isLeapYear = 0;
        System.out.println(isLeapYear);
    }
}
