import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numOfCases = sc.nextInt();
        for(int i = 0; i < numOfCases; i++){
            int A = sc.nextInt();
            int B = sc.nextInt();
            System.out.println("Case #"+(i+1)+": "+(A+B));
        }
    }
}
