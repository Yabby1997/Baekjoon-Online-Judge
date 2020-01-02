import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int sortArray[] = new int[3];
        
        sortArray[0] = sc.nextInt();
        sortArray[1] = sc.nextInt();
        sortArray[2] = sc.nextInt();
        
        for(int endOfIndex = 0; endOfIndex < sortArray.length; endOfIndex++){
            for(int currentIndex = 0; currentIndex < sortArray.length-1-endOfIndex; currentIndex++){
                if(sortArray[currentIndex] > sortArray[currentIndex+1]){
                    int temp = sortArray[currentIndex];
                    sortArray[currentIndex] = sortArray[currentIndex+1];
                    sortArray[currentIndex+1] = temp;
                }
            }
        }
        System.out.println(sortArray[1]);
    }
}
