import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfCases = Integer.parseInt(br.readLine());
        int counter = 0;
        String tmp = br.readLine();
        StringTokenizer st = new StringTokenizer(tmp);
        for(int i = 0; i < numOfCases; i++){
            int inputCase = Integer.parseInt(st.nextToken());
            int j = 2;
            while(true){
                if(inputCase == 1){
                    //System.out.println("@ 1 is NOT prime number");
                    break;
                }
                else if(inputCase == j){
                    //System.out.println("@ "+j+" only includes itself. it is prime number");
                    counter++;
                    break;
                }
                else if(inputCase % j == 0){
                    //System.out.println("@ "+inputCase+" is NOT prime number. it could represented like : "+j+" X "+(inputCase/j));
                    break;
                }
                else if(j > inputCase){
                    //System.out.println("@ "+inputCase+" is NOT prime number.");
                    break;
                }
                j++;
            }
        }
        System.out.println(counter);
    }
}
