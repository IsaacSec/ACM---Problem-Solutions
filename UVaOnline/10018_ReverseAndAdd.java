import java.io.*;

public class Main {
    public static void  main(String [] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int cases = Integer.parseInt(in.readLine());

        for (int i = 0; i < cases; i++) {
            int a = 0;
            long number = Long.parseLong(in.readLine());
            while(a<1000 || number < 4294967295l){
                a++;
                long reverse = getReverse(number);

                number = number + reverse;

                if(isPali(number)){
                    System.out.println(a+" "+number);
                    break;
                }

            }
        }
    }

    private static long getReverse(long number) {
        //String s = new StringBuilder(""+number).reverse().toString();
        return Long.parseLong(new StringBuilder(""+number).reverse().toString());
    }

    private static boolean isPali(long result){
        String s = ""+result;

        for (int i = 0; i < s.length(); i++) {
            char start = s.charAt(i);
            char end = s.charAt(s.length()-1-i);

            if(start != end){
                return  false;
            }
        }
        return true;
    }
}
