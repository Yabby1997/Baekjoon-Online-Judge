import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int infraCost = sc.nextInt();
        int productionCost = sc.nextInt();
        int productPrice = sc.nextInt();
        int breakEvenQtt = 0;
        
        if(productPrice - productionCost <= 0)
            breakEvenQtt = -1;
        else
            breakEvenQtt = infraCost/(productPrice - productionCost) + 1;
        
        System.out.println(breakEvenQtt);
    }
}
