import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));       //BUFFEREDREADER/WRITER, INPUTSTREAMREADER, OUTPUTSTREAMWRITER IN JAVA.IO.*
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws Exception{
        int numOfInputs = Integer.parseInt(br.readLine());
        for(int i = 0; i < numOfInputs; i++){
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);                                        //STRINGTOKENIZER(STRING) BASICALLY TOKENIZE STRING WITH " "
            int departure = Integer.parseInt(st.nextToken());
            int destination = Integer.parseInt(st.nextToken());
            int distance = destination - departure;
            System.out.println(alphaCentauri(distance));
        }
    }
    
    public static int alphaCentauri(int distance){
        int i = 1;
        int result = 0;
        while(true){
            distance = distance - i;
            if(distance <= 0){
                result = 2 * i - 1;
                break;
            }
            distance = distance - i;
            if(distance <= 0){
                result = 2 * i;
                break;
            }
            i++;
        }
        return result;
    }
}



