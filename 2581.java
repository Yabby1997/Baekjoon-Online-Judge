import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int minimum = 0;
        int sum = 0;
        int from = Integer.parseInt(br.readLine());
        int to = Integer.parseInt(br.readLine());
        for(int i = from; i <= to; i++){
            int j = 2;
            while(true){
                if(i == 1)
                    break;
                else if(i == j){
                    if(minimum == 0)
                        minimum = i;
                    sum = sum + i;
                    break;
                }
                else if(i % j == 0)
                    break;
                else if(j > i)
                    break;
                j++;
            }
        }
        if(minimum == 0)
            System.out.println(-1);
        else{
            System.out.println(sum);
            System.out.println(minimum);
        }
    }
}
