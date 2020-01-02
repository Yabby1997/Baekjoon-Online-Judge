import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int seedNum = sc.nextInt();
        System.out.println(factorial(seedNum));
    }
    public static int factorial(int inputNum){
        int result = 1;
        for(int i = inputNum; i > 0; i--){
            result = result * i;
        }
        return result;
    }
}
