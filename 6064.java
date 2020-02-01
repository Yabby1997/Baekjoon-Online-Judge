import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfCases = Integer.parseInt(br.readLine());
        for(int i = 0; i < numOfCases; i++){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            int maxX = Integer.parseInt(st.nextToken());
            int maxY = Integer.parseInt(st.nextToken());
            int inX = Integer.parseInt(st.nextToken());
            int inY = Integer.parseInt(st.nextToken());
            System.out.println(calculate(maxX, maxY, inX, inY));
        }
    }
    
    public static int calculate(int mX, int mY, int X, int Y){
        int year = X;
        while(true){
            if(mX > 40000 || mY > 40000 || X == 0 || Y == 0 || X > mX || Y > mY){
                return -1;
            }
            if(year > lcm(mX, mY)){
                return -1;
            }
            int yearY = year % mY == 0 ? mY : year % mY;
            if(yearY == Y){
                break;
            }
            year = year + mX;
        }
        return year;
    }
    
    public static int gdc(int a, int b){
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
    
    public static int lcm(int a, int b){
        return a * b / gdc(a, b);
    }
}
