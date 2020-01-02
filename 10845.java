import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]){
		
		int numOfOrders;
		String input;
		int i = 0;
		
		Scanner scan = new Scanner(System.in);
		Que que = new Que(10001);
		
		numOfOrders = scan.nextInt();
		
		while(i <= numOfOrders){
			
			input = scan.nextLine();
			
			if(input.contains("push")){
				StringTokenizer token = new StringTokenizer(input, " ");
				String command = token.nextToken();
				int data = Integer.parseInt(token.nextToken());
				
				que.push(data);
				i ++;
				
				continue;
			}
			
			else{
				switch(input){
				
				case "pop" :
					System.out.println(que.pop());
					break;
				
				case "size" :
					System.out.println(que.size());
					break;
				
				case "empty" :
					System.out.println(que.isEmpty());
					break;
					
				case "front" :
					System.out.println(que.front());
					break;
				
				case "back" :
					System.out.println(que.back());
					break;
				}
				i++;
			}
		}
	}
}

class Que {
	private int back;
	private int[] que;
	private int maxSize;
	
	int temp;

	public Que(int nowMaxSize){
		back = -1;
		maxSize = nowMaxSize;
		que = new int[maxSize];
	}
	
	public int isEmpty(){
		if(back == -1){
			return 1;
		}
		else
			return 0;
	}
	
	public int front(){
		if(back == -1){
			return -1;
		}
		else
			return que[0];
	}
	
	public int back(){
		if(back == -1){
			return -1;
		}
		else
			return que[back];
	}
	
	public int size(){
		return back + 1;
	}
	
	public int pop(){
		if(back == -1){
			return -1;
		}
		else{
			temp = que[0];
			for(int n = 0; n < back; n++){
				que[n] = que[n+1];
			}
			back --;
			return temp;
		}
	}
	
	public void push(int data){
		que[++back] = data;
	}
}
