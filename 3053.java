import java.io.*;
import java.lang.Math;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int inputNum = Integer.parseInt(br.readLine());
        System.out.printf("%6f\n%6f", (inputNum * inputNum * Math.PI), (inputNum * inputNum * 2.0));
    }
}


