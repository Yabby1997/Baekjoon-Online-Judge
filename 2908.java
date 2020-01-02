import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String inputString = sc.nextLine();
        String[] splitedInput = inputString.split(" ");
        
        int reversedA = inputConverter(splitedInput[0]);
        int reversedB = inputConverter(splitedInput[1]);
        
        if(reversedA > reversedB)
            System.out.println(reversedA);
        else if(reversedB > reversedA)
            System.out.println(reversedB);
    }
    
    public static int inputConverter(String givenString){
        StringBuffer sb = new StringBuffer();               
        sb.append(givenString);
        return Integer.parseInt(sb.reverse().toString());           //STRINGBUFFER != STRING
    }                                                               //STRING IS IMUTABLE BUT STRINGBUFFER OR BUILDER IS MUTABLE
}
