import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numOfCase = sc.nextInt();                       //NEXT INT DOESN'T REMOVE "NEW LINE" AND IT CAUSES ERROR WITH NEXT LINE
        sc.nextLine();                                      //REMOVE "NEW LINE" MANUALLY WITH NEXT LINE
        for(int i = 0; i < numOfCase; i++){
            String inputCase = sc.nextLine();
            System.out.println(calcCase(inputCase));    
        }
    }
    public static int calcCase(String givenCase){
        int sizeOfCase = givenCase.length();
        int[] scoreArray = new int[80];
        int totalScore = 0;
        if(givenCase.charAt(0) == 'O')  scoreArray[0] = 1;
        for(int i = 1; i < sizeOfCase; i++) if(givenCase.charAt(i) == 'O')  scoreArray[i] = scoreArray[i-1]+1;
        for(int i = 0; i < sizeOfCase; i ++)    totalScore = totalScore + scoreArray[i];
        return totalScore;
    }
}
