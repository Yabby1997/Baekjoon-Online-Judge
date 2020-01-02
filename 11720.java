import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();                 //nextInt와 nextLine같이 사용시 nextInt에 입력할때의 \n이 nextLine에 입력되어버림.
        String num = sc.next();                    //공백없이 받으려면 next()가 맞음. nextLine은 \n까지를 입력으로 받아옴. 그래서 nextInt와 사용시 씹힘 문제가 발생함.
        sc.close();
        
        int sum = 0;
        for(int i = 0; length > i; i++)
            sum = sum + num.charAt(i) - '0';        //자바도 동일하게 형변환. charAt을 이용해 인덱스로 문자 추출
        
        System.out.println(sum);
    }
}
