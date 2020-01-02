import java.io.*;
import java.util.StringTokenizer;

class Stack{
    private int topIndex;
    private int[] stack;
    
    public Stack(int inputSize){
        this.topIndex = -1;
        this.stack = new int[inputSize];
    }
    
    public int returnSize(){
        return this.topIndex + 1;
    }
    
    public int isEmpty(){
        if(returnSize() == 0)
            return 1;
        else
            return 0;
    }
    
    public int topElement(){
        if(topIndex < 0)
            return -1;
        else
            return stack[topIndex];
    }
    
    public int pop(){
        if(topIndex < 0)
            return -1;
        else
            return stack[topIndex--];
    }
    
    public void push(int inputNumber){
        stack[++topIndex] = inputNumber;
    }
}
public class Main{
    public static void main(String[] args) throws IOException{
        Stack stack = new Stack(100000);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfInputs = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < numOfInputs; i++){
            String temp = br.readLine();
            StringTokenizer st = new StringTokenizer(temp);
            String command = st.nextToken();
            if(command.equals("push")){
                int x = Integer.parseInt(st.nextToken());
                stack.push(x);
            }
            else if(command.equals("pop")){
                System.out.println(stack.pop());
            }
            else if(command.equals("size")){
                System.out.println(stack.returnSize());
            }
            else if(command.equals("empty")){
                System.out.println(stack.isEmpty());
            }
            else if(command.equals("top")){
                System.out.println(stack.topElement());
            }
        }
    }
}
