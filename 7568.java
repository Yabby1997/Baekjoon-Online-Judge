import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int weight[] = new int[50];
        int height[] = new int[50];
        int result[] = new int[50];
        
        int numOfCases = Integer.parseInt(br.readLine());
        for(int i = 0; i < numOfCases; i++){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            weight[i] = Integer.parseInt(st.nextToken());
            height[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i = 0; i < numOfCases; i++){
            int counter = 1;
            for(int j = 0; j < numOfCases; j++){
                if(weight[j] > weight[i] && height[j] > height[i])
                    counter++;
            }
            result[i] = counter;
        }
        for(int i = 0; i < numOfCases; i ++){
            System.out.print(result[i]+" ");
        }
    }
}
