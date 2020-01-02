import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numA = sc.nextInt();
        int numB = sc.nextInt();
        int A = numB / 100;
        int B = (numB - A * 100) / 10;
        int C = numB - A * 100 - B * 10;
        
        System.out.println(numA * C);
        System.out.println(numA * B);
        System.out.println(numA * A);
        System.out.println(numA * numB);
    }
}
