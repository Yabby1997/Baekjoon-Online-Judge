import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String temp = br.readLine();
        StringTokenizer st = new StringTokenizer(temp);
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken()) - x;
        int h = Integer.parseInt(st.nextToken()) - y;
        
        int minimum = x;
        int inputNums[] = {x, y, w, h};
        
        for(int i = 0; i < 4; i++){
            if(inputNums[i] < minimum)
                minimum = inputNums[i];
        }
        System.out.println(minimum);
    }
}
