import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {


    static void superStack(String[] operations) {
        Stack<Integer> st = new Stack<>();

        for(int i=0; i<operations.length; i++){
            String instr[] = operations[i].split(" ");

            if(instr[0].equals("push")){
                int val = Integer.parseInt(instr[1]);
                st.push(val);
            }else if(instr[0].equals("pop")){
                st.pop();
            }else if(instr[0].equals("inc")){
                int count = Integer.parseInt(instr[1]);
                int addValue = Integer.parseInt(instr[2]);

                // Stack<Integer> temp = new Stack<>();

                // while(!st.isEmpty()){
                //     temp.add(st.pop());
                // }

                // while(count-- > 0){
                //     st.add(temp.pop()+addValue);
                // }

                // while(!temp.isEmpty()){
                //     st.add(temp.pop());
                // }

                while(count-- > 0){
                    st.set(count,st.get(count)+addValue);
                }
            }

            if(st.isEmpty()){
                System.out.println("EMPTY");
            }else{
                System.out.println(st.peek());
            }
        }
    }

    public static void main(String[] args)  {
        Scanner in = new Scanner(System.in);
        int operations_size = 0;
        operations_size = Integer.parseInt(in.nextLine().trim());

        String[] operations = new String[operations_size];
        for(int i = 0; i < operations_size; i++) {
            String operations_item;
            try {
                operations_item = in.nextLine();
            } catch (Exception e) {
                operations_item = null;
            }
            operations[i] = operations_item;
        }

        superStack(operations);
        
    }
}
