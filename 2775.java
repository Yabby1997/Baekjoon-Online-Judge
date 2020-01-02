import java.util.StringTokenizer;
import java.io.*;

public class Main{
    public static int[][] apartment = new int[15][15];
    
    public static void initialize(){
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                apartment[i][j] = 0;
            }
        }
        for(int i = 1; i < 15; i++){
            apartment[0][i] = i;
        }
        for(int i = 0; i < 15; i++){
            apartment[i][0] = 0;
        }
    }
    
    public static void calculate(){
        for(int i = 1; i < 15; i++){
            for(int j = 1; j < 15; j++){
                apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
            }
        }
    }
    
    public static void show(){
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                System.out.print(apartment[i][j]+" ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) throws IOException{
        initialize();
        calculate();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tcTemp = br.readLine();
        int numOfCases = Integer.parseInt(tcTemp);
        for(int i = 0; i < numOfCases; i++){
            int flr = Integer.parseInt(br.readLine());
            int rm = Integer.parseInt(br.readLine());
            System.out.println(apartment[flr][rm]);
        }
    }
}
