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

    /*
     * Complete the 'maxProfit' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER costPerCut
     *  2. INTEGER salePrice
     *  3. INTEGER_ARRAY lengths
     */

    public static int maxProfit(int costPerCut, int salePrice, List<Integer> lengths) {
        int max = 0;
        for(int i : lengths){
            if(i > max){
                max = i;
            }
        }

        long maxRevenue = 0;

        while(max > 0){
            int len = max;           
            int totalCuts = 0;
            int peices = 0;
            
            for(int wood : lengths){

                if(wood < len)
                    continue;

                boolean extra = false;
                int extraCut = 0;
                while(wood%len != 0){
                    extra = true;
                    wood--;
                }
                if(extra){
                    extraCut = 1;
                }

                int regularCut = wood/len - 1;

                if((len*(wood/len)*salePrice)-(regularCut+extraCut)*costPerCut < 0){
                    continue;
                }

                totalCuts += extraCut + regularCut;

                peices += wood/len;
            }

            long revenue = peices*len*salePrice - totalCuts*costPerCut;

            if(revenue > maxRevenue){
                maxRevenue = revenue;
            }
            
            max--;
        }

        return (int)maxRevenue;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int costPerCut = Integer.parseInt(bufferedReader.readLine().trim());

        int salePrice = Integer.parseInt(bufferedReader.readLine().trim());

        int lengthsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> lengths = IntStream.range(0, lengthsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.maxProfit(costPerCut, salePrice, lengths);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
