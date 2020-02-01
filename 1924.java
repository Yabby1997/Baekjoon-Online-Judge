import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] daysInWeeks = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        int month = sc.nextInt();
        int date = sc.nextInt();
        int days = 0;
        sc.close();
        
        for(int i = 0; month - 1 > i; i++)
            days = days + daysInMonths[i];
        days = days + date;
      
        System.out.println(daysInWeeks[days%7]);
    }
}
