import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String[] croatianAlpha = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
        String inputString = sc.nextLine();
        
        for(int i = 0; i < 8; i++){
            if(inputString.contains(croatianAlpha[i])){
                inputString = inputString.replaceAll(croatianAlpha[i], "@");
            }
        }
        System.out.println(inputString.length());
    }
}
