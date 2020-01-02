import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int givenNumber = sc.nextInt();
        int output = 0;
        sc.close();
        
        for(int i = 0; givenNumber >= i; i++)
            output = output + i;
        
        System.out.println(output);
    }
}
