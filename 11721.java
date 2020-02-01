import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        sc.close();
        
        for(int i = 0; i < input.length(); i++){            //C에선 strlen(), java에선 .length()
            System.out.print(input.charAt(i));                //C에선 char 배열의 index로 생각, java에서는 .charAt()
            if(i % 10 == 9)    System.out.println();
        }
    }
}
