import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int[] stringArray = new int[10];
        String ABCstring = Integer.toString(A*B*C);
        for(int i = 0; i < ABCstring.length(); i++){
            if(ABCstring.charAt(i) == '0')  stringArray[0]++;
            else if(ABCstring.charAt(i) == '1')  stringArray[1]++;
            else if(ABCstring.charAt(i) == '2')  stringArray[2]++;
            else if(ABCstring.charAt(i) == '3')  stringArray[3]++;
            else if(ABCstring.charAt(i) == '4')  stringArray[4]++;
            else if(ABCstring.charAt(i) == '5')  stringArray[5]++;
            else if(ABCstring.charAt(i) == '6')  stringArray[6]++;
            else if(ABCstring.charAt(i) == '7')  stringArray[7]++;
            else if(ABCstring.charAt(i) == '8')  stringArray[8]++;
            else    stringArray[9]++;
        }
        for(int i = 0; i < 10; i++) System.out.println(stringArray[i]);
    }
}
