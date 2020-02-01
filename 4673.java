import java.util.Arrays;
//to use Arrays class

public class Main{
    public static void main(String[] args){
        int[] kaprekarArray = new int[10100];               //result of kaprekarFunc exceed 10000. ArrayIndexOutOfBoundException may occur
        Arrays.fill(kaprekarArray, 0);                      //fill array with 0. it needs to import java.util.Arrays
        for(int i = 0; i < 10000; i++)  kaprekarArray[kaprekarFunc(i)]++;
        for(int i = 0; i < 10000; i++)  if(kaprekarArray[i] == 0)   System.out.println(i);
    }
    public static int kaprekarFunc(int seedNumber){
        int j = seedNumber/1000;
        int k = (seedNumber-j*1000)/100;
        int m = (seedNumber-j*1000-k*100)/10;
        int n = seedNumber-j*1000-k*100-m*10;
        
        return seedNumber+j+k+m+n;
    }
}
