import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int inputNumber = sc.nextInt();
        if(inputNumber < 1 || inputNumber > 1000)   System.exit(0);
        else    System.out.println(checkNum(inputNumber));
    }
    public static int checkNum(int givenNumber){
        int counter = 0;
        for(int currentNumber = 1; currentNumber < givenNumber+1; currentNumber++){
            int j = currentNumber/1000;
            int k = (currentNumber-j*1000)/100;
            int m = (currentNumber-j*1000-k*100)/10;
            int n = currentNumber-j*1000-k*100-m*10;
            
            if(j == 0 && k == 0)  counter++;
            else if(j == 0 && k-m == m-n)  counter++;         
        }
    	return counter;
    }
}
