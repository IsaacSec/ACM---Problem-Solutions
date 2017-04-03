
public class test {
    
    public static void main(String[] args) {
        int x = 40;
        System.out.println(gcd(2, 40));
        
    }
    
    public static int gcd (int a, int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    
    
    
}
