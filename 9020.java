import java.io.*;
import java.lang.Math;

public class Main{
    public static void main(String[] args) throws IOException{
        boolean primeNumber[] = new boolean[10001];
        for(int i = 0; i < 10001; i++)
            primeNumber[i] = true;
        primeNumber[0] = false;
        primeNumber[1] = false;
        
        for(int i = 2; i < 10001; i++){
            for(int j = 2; j <= Math.sqrt(10001); j++){
                if(i * j >= 10001)
                    break;
                else
                    primeNumber[i * j] = false;
            }
        }
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfCases = Integer.parseInt(br.readLine());
        for(int i = 0; i < numOfCases; i++){
            int inputNum = Integer.parseInt(br.readLine());
            for(int j = inputNum/2; j > 1; j--){
                if(primeNumber[j] == true && primeNumber[inputNum - j] == true){
                    System.out.println(j+" "+(inputNum - j));
                    break;
                }
            }
        }
    }
}
