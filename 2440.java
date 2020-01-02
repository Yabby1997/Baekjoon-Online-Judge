import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int input;
        
        for(input = sc.nextInt(); input > 0; input--){
            for(int i = 1; input >= i; i++)
                System.out.print("*");
            System.out.println();
        }
    }
}
