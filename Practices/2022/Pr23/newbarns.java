import java.io.*;
import java.util.*;

public class newbarns {
    public static int[] longest;
    public static boolean[] visited;
    public static ArrayList<ArrayList<Integer>> graph;
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        longest = new int[(int)1e5+1];
        visited = new boolean[(int)1e5+1];
        graph = new ArrayList<>();

        int numQ = in.nextInt();
        while(numQ-->0){

            char type = in.next().charAt(0);
            if (type == 'B') {
                int from = in.nextInt()-1;
                if(from == -2) graph.add(new ArrayList<>());
                else{
                    graph.get(from).add(graph.size());
                    graph.add(new ArrayList<>());
                    graph.get(graph.size()-1).add(from);
                    refresh(graph.size()-1);
                }
            } else {
                out.println(longest[in.nextInt()-1]);
            }

        }

        out.flush();

    }

    private static void refresh(int node) {
        longest[node] = longest[graph.get(node).get(0)]+1;
        DFS(node, 0);
    }

    private static void DFS(int node, int dist) {
        longest[node] = Math.max(longest[node], dist);
        visited[node] = true;
        for (var next : graph.get(node))
            if(!visited[next])
                DFS(next, dist+1);
        visited[node] = false;
    }
}

class FastScanner {
    BufferedReader br; StringTokenizer st;
    public FastScanner() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StringTokenizer(br.readLine());
        } catch (Exception e){e.printStackTrace();}
    }
    public String next() {
        if (st.hasMoreTokens()) return st.nextToken();
        try {st = new StringTokenizer(br.readLine());}
        catch (Exception e) {e.printStackTrace();}
        return st.nextToken();
    }
    public int nextInt() {return Integer.parseInt(next());}
    public long nextLong() {return Long.parseLong(next());}
    public double nextDouble() {return Double.parseDouble(next());}
    public String nextLine() {
        StringBuilder line = new StringBuilder();
        if(st.hasMoreTokens()) line.append(st.nextToken());
        else try {return br.readLine();}catch(IOException e){e.printStackTrace();}
        while(st.hasMoreTokens()) line.append(" "+st.nextToken());
        return line.toString();
    }
}