import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



class Result {

    public static String featuredProduct(List<String> products) {

    HashMap<String,Integer> map = new HashMap<>();
        for(String s : products){
            if(map.containsKey(s)){
                map.replace(s,map.get(s)+1);
            }
            else{
                map.put(s,1);
            }
        }

        TreeMap<String,Integer> sortedMap = new TreeMap<>(map);

        Set set = sortedMap.entrySet();
        Iterator itr = set.iterator();
        int max=0;
        String s="";
        while(itr.hasNext()){
            Map.Entry me = (Map.Entry)itr.next();
            if((Integer)me.getValue() >= max){
                s = (String)me.getKey();
                max = (Integer)me.getValue();
            }

            //System.out.println("Key : "+me.getKey() + "  Value :" + me.getValue());
        }

        return s;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int productsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> products = IntStream.range(0, productsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        String result = Result.featuredProduct(products);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
