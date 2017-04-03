
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Vector;


public class tobbyarray {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String line ;
        while ( (line = input.readLine()) != null){
            StringTokenizer st = new StringTokenizer(line, " ");
            int size, numQueries;
            size = Integer.parseInt(st.nextToken());
            numQueries = Integer.parseInt(st.nextToken());
            
            line = input.readLine();
            StringTokenizer st2 = new StringTokenizer(line, " ");
            int []array = new int[size];
            
            for (int i = 0; i < size; i++) {
                int currentElement;
                currentElement = Integer.parseInt(st2.nextToken());
                array[i] = currentElement;
            }
            for (int i = 0; i < numQueries; i++) {
                line = input.readLine();
                StringTokenizer st3 = new StringTokenizer(line, " ");
                int min,max,pos;
                min = Integer.parseInt(st3.nextToken());
                max = Integer.parseInt(st3.nextToken());
                pos = Integer.parseInt(st3.nextToken());
                calculateQuery(min,max,pos, array);
            }
   
        }
        
    }
    
    public static void calculateQuery(int min, int max, int pos, int []array){
        int newSize = max-min+1;
        int[] newArray = Arrays.copyOfRange(array, min-1, max);
        Arrays.sort(newArray);
        System.out.println(newArray[pos-1]);
    }
}
