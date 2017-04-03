
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrador
 */


public class ancestors {
    public static int offsetStr(String a, String b){
        boolean gotMatch = false;
        int counter = 0, pad = 0;
        
        int i;
        for(i = 0; i<a.length(); i++){
            if(a.charAt(i) == (b.charAt(0))){
                gotMatch = true;
                if(i == a.length()-1){
                    break;
                   
                }
     
                if(a.charAt(i+1) == b.charAt(0)){
                    i++;
                }
                
                
                break;
            }
            else{
                
            }
        }
        String sequence = a.substring(0, i);
        
        
            
        if(gotMatch){
            int zero = 0;
            for(int j = i; j<=a.length()-i+2; j++){
                //System.out.println("a: "+a.charAt(j)+ " b:"+b.charAt(zero));
                if(a.charAt(j) == b.charAt(zero)){
                    sequence = sequence + a.charAt(j);
                    counter++;
                    
                }
                else{
                    sequence = sequence + "X";
                }
                zero++;
            }
            System.out.println(counter+"\n"+sequence+b.substring(zero, b.length() )+"\n");
            //
        }
        else{
            System.out.println("0\nNo matches\n");
        }
        return 0;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader bu = new BufferedReader(new InputStreamReader(System.in));
        
        String a;        
        while((a = bu.readLine()) != null){
            String b = bu.readLine();
            System.out.println(a+"  "+b);
            int id = offsetStr(a, b);
            bu.readLine();
        }
        
    }
}
