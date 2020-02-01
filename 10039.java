import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] guys = new int[5];
        int[] scores = new int[5];
        int totalScore = 0;
        int averageScore = 0;
        for(int i = 0; i < 5; i++){
            guys[i] = sc.nextInt();
        }
        for(int i = 0; i < 5; i++){
            if(guys[i] < 40){
                scores[i] = 40;
            }
            else{
                scores[i] = guys[i];
            }
        }
        for(int i = 0; i < 5; i++){
            totalScore = totalScore + scores[i];
        }
        averageScore = totalScore/5;
        System.out.println(averageScore);
    } 
}
