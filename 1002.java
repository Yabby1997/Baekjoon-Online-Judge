import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x1, y1, r1, x2, y2, r2, distance, result;
        int numOfCases = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < numOfCases; i++){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            x1 = Integer.parseInt(st.nextToken());
            y1 = Integer.parseInt(st.nextToken());
            r1 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());
            r2 = Integer.parseInt(st.nextToken());
            distance = square(x2 - x1) + square(y2 - y1);
            
            if(distance == 0 && r1 == r2)
                result = -1;
            else if(distance < square(r1 - r2) || distance > square(r1 + r2))
                result = 0;
            else if(distance == square(r1 + r2) || distance == square(r1 - r2))
                result = 1;
            else
                result = 2;
        
            System.out.println(result);
        }
    }
    
    public static int square(int x){
        return x * x;
    }
}
