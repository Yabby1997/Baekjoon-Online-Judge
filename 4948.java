import java.io.*;
import java.lang.Math;

public class Main{
    public static void main(String[] args) throws IOException{
        boolean primeNumber[] = new boolean[246913];
        for(int i = 0; i < 246913; i++)
            primeNumber[i] = true;
        
        for(int i = 2; i < 246913; i++){
            for(int j = 2; j <= Math.sqrt(246913); j++){
                if(i * j >= 246913) 
                    break;
                else{
                    primeNumber[i*j] = false;
                }
            }
        }
        primeNumber[0] = false;
        primeNumber[1] = false;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int inputNum = 1;
        int counter = 0;
        while(inputNum != 0){
            inputNum = Integer.parseInt(br.readLine());
            if(inputNum == 0)
                break;
            else{
                for(int i = inputNum + 1; i <= 2 * inputNum; i++)
                    if(primeNumber[i] == true)
                        counter++;
                System.out.println(counter);
                counter = 0;
            }
        }
    }
}
