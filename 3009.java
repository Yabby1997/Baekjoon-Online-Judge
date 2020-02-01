import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static int x[] = new int[3];
    public static int y[] = new int[3];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 3; i++){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(findCoordinate(x)+" "+findCoordinate(y));
    }
    public static int findCoordinate(int[] target){
        int result = 0;
        if(target[0] == target[1])
            result = target[2];
        else if(target[0] == target[2])
            result = target[1];
        else if(target[1] == target[2])
            result = target[0];
        return result;
    }
}
