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
     * Complete the 'stockPairs' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY stocksProfit
     *  2. LONG_INTEGER target
     */


    public static boolean bSearch(List<Integer> arr, long target){
        int l = 0;
        int r = arr.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(arr.get(mid) == target){
                return true;
            }else if(arr.get(mid) > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return false;
    }

    public static int stockPairs(List<Integer> stocksProfit, long target) {
    // Write your code here
        Collections.sort(stocksProfit);
        int prev = Integer.MIN_VALUE;
        int count=0;
        int size = stocksProfit.size();
        for(int i=0; i<size;i++){
            int val = stocksProfit.get(i);
            if(prev == val){
                continue;
            }
            prev = val;

            boolean found =  bSearch(stocksProfit,target-val);
            if(found){
                
                if(val+val == target && i<size-1 && stocksProfit.get(i+1) == val){
                    count += 2;
                }else{
                    count++;
                }
                
            }
        }

        return count/2;
    }
}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int stocksProfitCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> stocksProfit = IntStream.range(0, stocksProfitCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        long target = Long.parseLong(bufferedReader.readLine().trim());

        int result = Result.stockPairs(stocksProfit, target);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
