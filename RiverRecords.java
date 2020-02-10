/*
River Records
A meteorologist maintains a record of water level readings taken on a nearby river.  Initially, there was an average level that is considered to be level 0.  Subsequent readings show the height in millimeters above or below that zero level, at regular intervals.  One of the figures to determine is the maximum height above a previously recorded value that has been achieved to date.  Given the complete array of records collected, determine the maximum difference between any reading versus any prior reading, the trailing record.  If there is never a lower prior reading, return -1.
 
Example
levels = [5, 3, 6, 7, 4]
 
There are no earlier readings than levels[0].
There is no earlier reading with a value lower than levels[1].
There are two lower earlier readings with a value lower than levels[2] = 6:
•	levels[2] - levels[1] = 6 - 3 = 3
•	levels[2] - levels[0] = 6 - 5 = 1
There are three lower earlier readings with a lower value than levels[3] = 7:
•	levels[3] - levels[2] = 7 - 6 = 1
•	levels[3] - levels[1] = 7 - 3 = 4
•	levels[3] - levels[0] = 7 - 5 = 2
There is one lower earlier reading with a lower value than arr[4] = 4:
•	levels[4] - levels[1] = 4 - 3 = 1
 
The maximum trailing record is levels[3] - levels[1] = 4.
 
Example
levels = [4, 3, 2, 1]
 
No item in levels has a lower earlier reading, therefore return -1
 
Function Description 
Complete the function maximumTrailing in the editor below.
 
maximumTrailing has the following parameter(s):
    int levels[n]:  an array of integers
Returns:
    int: an integer that represents the maximum trailing record, or -1 if no element in levels has a lower earlier reading
 
Constraints
•	1 ≤ n ≤ 2 × 105
•	−106 ≤ levels[i] ≤ 106  and  0 ≤ i < n
 
Input Format For Custom TestingSample Case 0
Sample Input 0
STDIN         Function
-----         --------
7       →     levels[] size n = 7
2       →     levels = [2, 3, 10, 2, 4, 8, 1]
3       
10     
2      
4      
8       
1         
 
Sample Output
8
Explanation
 
Differences are calculated as:
•	3 - [2] = [1]
•	10 - [3, 2] = [7, 8]
•	4 - [2, 3, 2] = [2, 1, 2]
•	8 - [4, 2, 3, 2] = [4, 6, 5, 6]
The maximum trailing record is 10 - 2 = 8.



*/




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
     * Complete the 'maxTrailing' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY levels as parameter.
     */

    public static int maxTrailing(List<Integer> levels) {
    // Write your code here
        int res = -1;
        int min = levels.get(0);

        for(int val : levels){
            if(val > min){
                int ans = val - min;
                if(ans > res)
                    res = ans;
            }
            else
                min = val;
        }

        return res;
    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int levelsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> levels = IntStream.range(0, levelsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.maxTrailing(levels);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
