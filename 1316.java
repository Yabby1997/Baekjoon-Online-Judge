import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String alphabetString = "abcdefghijklmnopqrstuvwxyz";                                   //ALPHABET STRING FOR COMPARING CHAR FROM INPUT
        int nonGroupedWords = 0;
        
        int numOfCases = sc.nextInt(); 
        sc.nextLine();                                                                          //NEXT LINE RIGHT AFTER NEXT INT REMOVES NEW LINE
        
        for(int i = 0; i < numOfCases; i++){
            int nonGroupedChar = 0;
            int[] recentlyAppeared = new int[26];
            
            for(int j = 0; j < 26; j++)                                                         //INITIALIZE ALL MEMBERS OF ARRAY RECENTLYAPPEARED, -99 WHICH MEANS "NOT ASSIGNED"
                recentlyAppeared[j] = -99;
                
            String inputString = sc.nextLine();
            
            for(int j = 0; j < inputString.length(); j++){
                for(int k = 0; k < 26; k ++){
                    if(inputString.charAt(j) == alphabetString.charAt(k)){ 
                        if(recentlyAppeared[k] == -99 || recentlyAppeared[k] == j-1)            //CASE : NOT ASSIGNED OR GROUPED
                            recentlyAppeared[k] = j;
                        else                                                                    //CASE : ALREADY ASSIGNED AND NOT GROUPED
                            nonGroupedChar++;                                                   //COUNT NON GROUPED CHARS
                    }
                }
            }
            if(nonGroupedChar > 0)                                                              //IF NON GROUPED CHARS MORE THAN 0, IT MEANS IT'S NON GROUPED WORD
                nonGroupedWords++;
        }
        System.out.println(numOfCases - nonGroupedWords);                                       //GROUPED WORDS = NUM OF CASES - NON GROUP WORDS
    }
}
