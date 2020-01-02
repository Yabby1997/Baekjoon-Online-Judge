import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] numArray = new int[9];
        int maxValue = 0;
        int maxIndex = 0;
        for(int i = 0; i < 9; i++){
            numArray[i] = sc.nextInt();
            if(maxValue < numArray[i]){
                maxValue = numArray[i];
                maxIndex = i;
            }
        }
        System.out.println(maxValue);
        System.out.println(maxIndex+1);
    }
}
