import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        int x, y, z;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());
            
            if(x == 0 && y == 0 && z == 0)
                break;
            else{
                if(x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x)
                    System.out.println("right");
                else
                    System.out.println("wrong");
            }
        }        
    }
}
