import java.util.Scanner;

 
public class Main{
    public static void main (String[]args){
        Scanner sc = new Scanner (System.in);
        String alphabetString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
        int[] alphabetIndex = new int[26];
        int mostAppearedIndex = 0;
        
        String inputString = sc.nextLine ();
        inputString = inputString.toUpperCase ();
    
        for (int i = 0; i < 26; i++)
            alphabetIndex[i] = 0;
    
        for (int i = 0; i < inputString.length (); i++){
            for (int j = 0; j < 26; j++){
                if (inputString.charAt (i) == alphabetString.charAt (j)){
                    alphabetIndex[j]++;
                }
	        }
        }
        
        for (int i = 0; i < 26; i++){
            if (alphabetIndex[i] > alphabetIndex[mostAppearedIndex])
                mostAppearedIndex = i;
        }
 
        for (int i = 0; i < 26; i++){
            if (i != mostAppearedIndex && alphabetIndex[i] == alphabetIndex[mostAppearedIndex]){
	            mostAppearedIndex = 26;
	            break;
            }
            
        }
        
        System.out.println (alphabetString.charAt(mostAppearedIndex));
    }
}


