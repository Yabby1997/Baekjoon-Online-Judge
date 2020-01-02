import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int counter = 0;
        int[] remainderArray = new int[42];
        for(int i = 0; i < 42; i++)
            remainderArray[i] = 0;
            
        for(int i = 0; i < 10; i++){
            int tempIn = sc.nextInt();
            remainderArray[tempIn%42]++;
        }
        
        for(int i = 0; i < 42; i++){
            if(remainderArray[i] != 0)
                counter++;
        }
        
        System.out.println(counter);
    }
}
