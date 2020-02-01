import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int sugarAmount, output = 0;
        sugarAmount = sc.nextInt();
        output = countRecursively(sugarAmount, 0);
        System.out.println(output);
    }
    
    public static int countRecursively(int remainSugar, int count){
        int output = 0;
        if(remainSugar < 0)
            output = -1;
        else if(remainSugar == 0)
            output = count;
        else if(remainSugar % 5 == 0)
            output = count + remainSugar / 5;
        else if(remainSugar % 5 != 0)
            output = countRecursively(remainSugar - 3, count+1);
        return output;
    }
}
