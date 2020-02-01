import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cellNumber = sc.nextInt();
        int cellAmount = 1;
        int level = 0;
    
        if(cellNumber == 1)
            level = 1;
        else
            for(; cellAmount < cellNumber; level++)
                cellAmount = cellAmount + 6 * level;
        
        System.out.print(level);
    }
}
