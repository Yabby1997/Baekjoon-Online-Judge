import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numOfCases = sc.nextInt();
        int[] inputNums = new int[numOfCases];
        
        for(int i = 0; i < numOfCases; i++){
            inputNums[i] = sc.nextInt();
        }
        int minimum = inputNums[0];
        int maximum = inputNums[0];
        
        for(int i = 0; i < numOfCases; i++){
            if(inputNums[i] < minimum)
                minimum = inputNums[i];
            else if(inputNums[i] > maximum)
                maximum = inputNums[i];
        }
        System.out.println(minimum+" "+maximum);
    }
}
