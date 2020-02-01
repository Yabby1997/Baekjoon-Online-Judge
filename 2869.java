import java.io.*;
import java.lang.Math;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String temp = br.readLine();
        StringTokenizer st = new StringTokenizer(temp);
        double up = (double)Integer.parseInt(st.nextToken());
        double down = (double)Integer.parseInt(st.nextToken());
        double distance = (double)Integer.parseInt(st.nextToken());
        int numOfDays = (int)Math.ceil((distance - up)/(up - down)) + 1;
        bw.write(String.valueOf(numOfDays));                                                //BUFFEREDWRITER WRITE WRITES INTEGER BASED CHARACTORS (ASCII) IF YOU WANT TO PRINT INTEGER, USE STRING.VALUEOF()
        bw.flush();
        bw.close();
    }
}
