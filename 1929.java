import java.io.*;
import java.lang.Math;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        boolean primeNumber[] = new boolean[1000001];
        for(int i = 0; i < 1000001; i++)
            primeNumber[i] = true;
        
        for(int i = 2; i < 1000001; i++){
            for(int j = 2; j <= Math.sqrt(1000001); j++){
                if(i * j >= 1000001) 
                    break;
                else{
                    primeNumber[i*j] = false;
                }
            }
        }
        primeNumber[0] = false;
        primeNumber[1] = false;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String temp = br.readLine();
        StringTokenizer st = new StringTokenizer(temp);
        int from = Integer.parseInt(st.nextToken());
        int to = Integer.parseInt(st.nextToken());
        
        for(int i = from; i <= to; i++){
            if(primeNumber[i] == true)
                System.out.println(i);
        }
    }
}
