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
     * Complete the 'doesCircleExist' function below.
     *
     * The function is expected to return a STRING_ARRAY.
     * The function accepts STRING_ARRAY commands as parameter.
     */

    public static char moveRight(char dir){
        if(dir == 'N'){
            return 'E';
        }else if(dir == 'S'){
            return 'W';
        }else if(dir == 'E'){
            return 'S';
        }else{
            return 'N';
        }
    }

    public static char moveLeft(char dir){
        if(dir == 'N'){
            return 'W';
        }else if(dir == 'S'){
            return 'E';
        }else if(dir == 'E'){
            return 'N';
        }else{
            return 'S';
        }
    }

    public static List<String> doesCircleExist(List<String> commands) {
    // Write your code here
        ArrayList<String> result = new ArrayList<>();

        for(String instruction : commands){
            int cords[] = new int[]{0,0};
            int move[][] = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
            char curDirection = 'N';

            HashMap<Character,Integer> direction = new HashMap<>();
            direction.put('N',0);
            direction.put('S',1);
            direction.put('E',2);
            direction.put('W',3);

            int count = 4;
            boolean isCircle = false;
            while(count-- > 0){
                for(int i=0; i< instruction.length();i++){
                    char inst = instruction.charAt(i);
                    if(inst == 'R' ){
                        curDirection = moveRight(curDirection);
                    }else if(inst == 'L'){
                        curDirection = moveLeft(curDirection);
                    }else if(inst == 'G'){
                        int index = direction.get(curDirection);
                        cords[0] += move[index][0];
                        cords[1] += move[index][1];   
                    }
                }
            }

            if(cords[0] == 0 && cords[1] == 0){
                result.add("YES");
            }else{
                result.add("NO");
            }

        }
        
        return result;
    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int commandsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> commands = IntStream.range(0, commandsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        List<String> result = Result.doesCircleExist(commands);

        bufferedWriter.write(
            result.stream()
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
