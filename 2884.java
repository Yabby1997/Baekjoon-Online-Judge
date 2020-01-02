import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int outHour, outMinute;
        int inHour = sc.nextInt();
        int inMinute = sc.nextInt();
        
        if(inMinute < 45){
            outMinute = 15 + inMinute;
            outHour = inHour - 1;
        }
        else{
            outMinute = inMinute - 45;
            outHour = inHour;
        }
        if(outHour < 0){
            outHour = 24 + outHour;
        }
        
        System.out.print(outHour+" "+outMinute);
    }
}
