import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int numOfCase = sc.nextInt();
        int charIteration = 0;
        String inputString = "";
        
        sc.nextLine();
        for(int i = 0; i < numOfCase; i++){                         //IF YOU WANT TO TAKE TWO VALUE IN ONE LINE, SPLIT THEM INTO A ARRAY BY USING SPLIT METHOD
            String[] temp = sc.nextLine().split(" ");               //SPLIT METHOD WILL SPLIT ONE STRING INTO TWO OR MORE STRINGS WITH SPECIFIC CHARACTER
            charIteration = Integer.parseInt(temp[0]);              //USE INTEGER.PARSEINT TO CONVERT STRING INTO INT
            inputString = temp[1];
            
            for(int j = 0; j < inputString.length(); j++){
                for(int k = 0; k < charIteration; k++){
                    System.out.print(inputString.charAt(j));
                }
            }
            System.out.println();
        }
        sc.close();
    }
}
