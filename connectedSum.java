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

    public static void dfs(ArrayList<ArrayList<Integer>> adjL , boolean visited[] , int curr , int sum[]){
        visited[curr] = true;
        sum[0]++ ;
        for(int i=0; i<adjL.get(curr).size(); i++){
            int node = adjL.get(curr).get(i);
            if(!visited[node]){
                dfs(adjL,visited,node,sum);
            }
        }
    }

    public static int countConnectedSum(ArrayList<ArrayList<Integer>> adjL , boolean visited[], int n){

        int result = 0;

        for(int i=0; i<n; i++){
            if(visited[i] == false){
                int sum[] = new int[1];
                sum[0] = 0;
                dfs(adjL,visited,i,sum);
                result += Math.ceil(Math.sqrt(sum[0]));
            }
        }

        return result;
    }


    public static int connectedSum(int n, List<String> edges) {
        ArrayList<ArrayList<Integer>> adjL = new ArrayList<>();
        boolean visited[] = new boolean[n];

        for(int i=0; i<n; i++){
            visited[i] = false;
            adjL.add(new ArrayList<Integer>());
        }

        for(String edg : edges){
            String pairs[] = edg.split(" ");
            int v1 = Integer.parseInt(pairs[0]);
            int v2 = Integer.parseInt(pairs[1]);

            adjL.get(v1-1).add(v2-1);
            adjL.get(v2-1).add(v1-1);
        }

        int result = countConnectedSum(adjL,visited,n);
        return result;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        int edgesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> edges = IntStream.range(0, edgesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        int result = Result.connectedSum(n, edges);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
