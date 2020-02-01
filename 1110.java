import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int initialNumber = sc.nextInt();
        if(initialNumber < 0 || initialNumber > 99) System.exit(0);
        else System.out.println(getCycle(initialNumber, initialNumber, 1));
    }
    
    public static int getCycle(int seedNumber, int currentNumber, int cycle){
        int[] temp = new int[2];
        int nextNumber;
        temp[0] = (int)currentNumber/10;
        temp[1] = currentNumber%10;
        nextNumber = temp[1]*10+(temp[0]+temp[1])%10;
        if(seedNumber == nextNumber)    return cycle;
        else    return getCycle(seedNumber, nextNumber, cycle+1);
    }
}
