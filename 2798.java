import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String temp1 = br.readLine();
        String temp2 = br.readLine();
        StringTokenizer st1 = new StringTokenizer(temp1);
        StringTokenizer st2 = new StringTokenizer(temp2);
        
        int numOfCards = Integer.parseInt(st1.nextToken());
        int maxSum = Integer.parseInt(st1.nextToken());
        int cards[] = new int[100];
        int bestRecord = 0;
        
        for(int i = 0; i < numOfCards; i++)
            cards[i] = Integer.parseInt(st2.nextToken());
        
        for(int i = 0; i < numOfCards; i++){
            for(int j = i + 1; j < numOfCards; j++){
                for(int k = j + 1; k < numOfCards; k++){
                    if(cards[k] + cards[j] + cards[i] == maxSum){
                        bestRecord = maxSum;
                        break;
                    }
                    else if(cards[k] + cards[j] + cards[i] > bestRecord && cards[k] + cards[j] + cards[i] < maxSum)
                        bestRecord = cards[k] + cards[j] + cards[i];
                }
            }
        }
        System.out.println(bestRecord);
    }
}
