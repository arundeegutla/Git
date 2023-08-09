import java.util.Arrays;
import java.util.Scanner;

public class thewrathofkahn {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numNodes = in.nextInt();
        int numEdges = in.nextInt();
        int[][] graph = new int[numNodes + 2][numNodes + 2];

        for (int i = 1; i <= numNodes; i++) {
            graph[0][i] = 1;
            graph[i][numNodes + 1] = 1;
        }
        for (int i = 0; i < numEdges; i++) {
            int from = in.nextInt() + 1;
            int to = in.nextInt() + 1;
            graph[from][to] = 1;
        }

        FordFulkerson f = new FordFulkerson(graph);
        System.out.println(f.ff());
    }
}

class FordFulkerson {
    public int[][] graph;
    public int n;
    public int source;
    public int sink;
    final public static int oo = (int)1e9;
    public FordFulkerson(int[][] graph) {
        n = graph.length;
        source = 0;
        sink = n - 1;
        this.graph = graph;
    }
    public int ff() {
        boolean[] visited = new boolean[n];
        int flow = 0;
        while (true) {
            Arrays.fill(visited, false);
            int res = dfs(source, visited, oo);
            if (res == 0) {
                break;
            }
            flow +=  res;
        }
        return flow;
    }
    private int dfs(int v, boolean[] visited, int min) {
        if(v == sink)
            return min;
        if (visited[v]) {
            return 0;
        }

        visited[v] = true;
        int flow = 0;
        for (int i = 0; i < n; i++) {
            if (graph[v][i] > 0)
                flow = dfs(i, visited, Math.min(graph[v][i], min));
            if (flow > 0) {
                graph[v][i] -= flow;
                graph[i][v] += flow;
                return flow;
            }
        }
        return 0;
    }
}
