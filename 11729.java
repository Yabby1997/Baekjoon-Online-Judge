import java.util.Scanner;
import java.lang.Math;                                                                                      //TO USE POW METHOD IN JAVA.LANG.MATH
import java.io.*;                                                                                           //TO USE BUFFER READ AND WRITE

public class Main{
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));                 
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static void main(String[] args) throws Exception{                                                //BUFFEREDWRITER NEEDS THROWS EXCEPTION
        int inputNum = Integer.parseInt(br.readLine());                                                     //USE BUFFEREDREADER AND CONVERT STRING INTO INTEGER
        br.close();                                                                                         //CLOSE BUFFEREDREADER
        bw.write(((int)Math.pow(2, inputNum) - 1)+"\n");                                                    //MATH.POW CALCULATES POWER AND RETURN RESULT AS DOUBLE
        bw.flush();                                                                                         //FLUSH AFTER WRITE
        solveHanoiRecursively(inputNum, 1, 2, 3);
        bw.close();                                                                                         //CLOSE BUFFEREDWRITER
    }
    public static void solveHanoiRecursively(int currentNum, int from, int by, int to) throws Exception{
        if(currentNum == 1){
            bw.write(from+" "+to+"\n");                                                                     //BUFFEREDWRITER WRITE IS ALMOST SAME AS SYSTEM.OUT.PRINTLN BUT IT DOESN'T INCLUDE NEW LINE
            bw.flush();
        }
        else{
            solveHanoiRecursively(currentNum - 1, from, to, by);
            bw.write(from+" "+to+"\n");
            bw.flush();
            solveHanoiRecursively(currentNum - 1, by, from, to);
        }
    }
}
