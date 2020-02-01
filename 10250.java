import java.io.*;
import java.lang.Math;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfCases = Integer.parseInt(br.readLine());
        for(int i = 0; i < numOfCases; i++){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            double height = (double)Integer.parseInt(st.nextToken());
            double width = (double)Integer.parseInt(st.nextToken());
            double visitors = (double)Integer.parseInt(st.nextToken());
            int xx = (int)(visitors % height);
            if(xx == 0)
                xx = (int)height;
            int yy = (int)Math.ceil(visitors / height);
            System.out.printf("%d%02d\n", xx, yy);
        }
    }
}
