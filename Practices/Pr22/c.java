import java.util.ArrayList;
import java.util.Scanner;

public class c {
    public static int won = 0;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numVertices = in.nextInt();
        int p = in.nextInt();

        ArrayList<ArrayList<Edge>> g = new ArrayList<>();
        for (int i = 0; i < numVertices; i++) {
            int numEdges = in.nextInt();
            g.add(new ArrayList<>());
            g.get(i).add(new Edge(i, i));
            while (numEdges-->0)
                g.get(i).add(new Edge(i, in.nextInt() - 1));
        }

        double[][] probs = new double[numVertices][numVertices];

        for (int i = 0; i < probs.length; i++) {
            for (int j = 0; j < probs.length; j++) {
                boolean[] used = new boolean[numVertices];
                probs[i][j] = go(i, j, g, used);
            }
        }

        while (p-->0) {
            won = 0;
            int j = in.nextInt();
            int start = in.nextInt()-1;
            int end = in.nextInt()-1;
            System.out.println(j + " " + probs[start][end]);
        }
    }

    private static double go(int start, int end, ArrayList<ArrayList<Edge>> g, boolean[] used) {
        if (used[start]) {
            if (start == end) 
                won++;
            return 0;
        }

        double total = 0;
        used[start] = true;
        for (Edge e : g.get(start)) {
            if (e.to == end) 
                total += go(e.to, end, g, used);
            else 
                total += go(e.to, end, g, used);
        }
        
        used[start] = false;

        return total;
    }
}

class Edge {
    int from;
    int to;
    Edge(int from, int to){
        this.from = from;
        this.to = to;
    }
}