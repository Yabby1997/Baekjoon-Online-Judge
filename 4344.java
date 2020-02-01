import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numOfCases = sc.nextInt();
        for(int i = 0; i < numOfCases; i++){
            int numOfSubjects = sc.nextInt();
            int[] scoreArray = new int[numOfSubjects];
            float averageScore = 0;
            float result = 0;
            //if you don't initialize those two variables, value may affected by other cases which is not cool with this
            for(int j = 0; j < numOfSubjects; j++){
                scoreArray[j] = sc.nextInt();
            }
            averageScore = averageScore(scoreArray, scoreArray.length);
            System.out.format("%.3f%%\n", aboveAverageCounter(scoreArray, scoreArray.length, averageScore));
            //if you wanna find out array's size, use .length and in case of String, .length()
            //you can print under point position number by using function like above
        }
    }
    public static float averageScore(int[] array, int sizeOfArray){
        int sum = 0;
        for(int i = 0; i < sizeOfArray; i++)    sum = sum + array[i];
        return (float)sum/sizeOfArray;
    }
    public static float aboveAverageCounter(int[] array, int sizeOfArray, float averageScore){
        int averageAboveCount = 0;
        for(int i = 0; i < sizeOfArray; i++)    if(array[i] > averageScore) averageAboveCount++;
        return (float)(averageAboveCount*100)/sizeOfArray;
    }
}



