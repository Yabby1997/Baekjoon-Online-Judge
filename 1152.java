import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String inputString = sc.nextLine();
        String trimmedString = inputString.trim();                                                                  //string.trim() trims front and lear of string
        int wordCounter = 1;
        if(trimmedString.length() == 0) wordCounter = 0;                                                            //trimmed string may have no word in string
        for(int i = 0; i < trimmedString.length(); i++)    if(trimmedString.charAt(i) == ' ')  wordCounter++;       //string.length() returns length of string
        System.out.println(wordCounter);
    }
}
