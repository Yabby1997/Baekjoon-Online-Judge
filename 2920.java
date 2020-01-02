import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] inputMelody = new int[8];
        int[] substractMelody = new int[7];
        int output = 0;
        
        for(int i = 0; i < 8; i++){
            inputMelody[i] = sc.nextInt();
        }
        for(int i = 0; i < 7; i++){
            substractMelody[i] = inputMelody[i+1]-inputMelody[i];
        }
        for(int i = 0; i < 6; i++){
            if(substractMelody[i] == substractMelody[i+1]){
                output = substractMelody[i];
            }
            else{
                output = 0;
                break;
            }
        }
        switch(output){
            case 0 :
                System.out.println("mixed");
                break;
            case 1 :
                System.out.println("ascending");
                break;
            case -1 :
                System.out.println("descending");
                break;
        }
    }
}
