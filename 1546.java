import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numOfInput = sc.nextInt();
        int scoreArray[] = new int[numOfInput];
        int bestScore = 0;
        int totalScore = 0;
        double result;
        
        for(int i = 0; i < numOfInput; i++)    scoreArray[i] = sc.nextInt();
        for(int i = 0; i < numOfInput; i++)    if(bestScore < scoreArray[i])    bestScore = scoreArray[i];
        for(int i = 0; i < numOfInput; i++)    totalScore = totalScore + scoreArray[i];
        
        result = (double)(totalScore*100)/(bestScore*numOfInput);
        System.out.println(result);
    }
}
