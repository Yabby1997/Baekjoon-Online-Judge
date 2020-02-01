import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String inputString = sc.nextLine();
        String alphabetArray = "abcdefghijklmnopqrstuvwxyz";
        
        for(int i = 0; i < 26; i++){
            System.out.print(inputString.indexOf(alphabetArray.charAt(i))+" ");
        }
    }
}
