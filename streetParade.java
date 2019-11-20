import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String args[] ) throws Exception {
       
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        

        while(n != 0){
            int arr[] = new int[n];
            int res[] = new int[n];
            Stack<Integer> s = new Stack<>();

            for(int i=0;i<n;i++)
                arr[i] = sc.nextInt();
            
            int need = 1,index=0,flag=0;

            for(int i=0;i<n;i++){
                if(arr[i] == need){
                    res[index++] = arr[i];
                    need++;
                }
                else{
                    if(s.empty()){
                        s.push(arr[i]);
                    }
                    else if(s.peek() == need){
                        res[index++] = s.peek();
                        s.pop();
                        need++;
                        i--;   // need is fulfilled by stack not by array.
                    }
                    else if(s.peek() < arr[i]){
                        flag = 1;
                        break;
                    }
                    else
                        s.push(arr[i]);
                    
                }
                
            }


        while(s.empty() == false){
            res[index++] = s.peek();
            s.pop();
        }


        if(flag == 1)
            System.out.println("no");
        else{
            for(int i=0;i<n;i++){
                if(res[i] != i+1){
                    flag = 1;
                    break;
                }
            }

            if(flag == 1)
                System.out.println("no");
            else
                System.out.println("yes");
        }


        n = sc.nextInt();

        }

    }
}
