import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int lengthOfInput = sc.nextInt();
        int X = sc.nextInt();
        
        for(int i = 0; i < lengthOfInput; i++){
            int currentInput = sc.nextInt();
            if(currentInput < X)    System.out.print(currentInput+" ");
        }
    }
}
