import java.util.ArrayList;
import java.util.Scanner;


public class redblue {

    public static ArrayList<Edge> edges;
    public static int numNodes;
    public static int blueEdges;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        numNodes = in.nextInt();
        int numEdges = in.nextInt();
        blueEdges = in.nextInt();

        int blueCount = 0;
        edges = new ArrayList<>();

        
        for (int i = 0; i < numEdges; i++) 
        {
            char weight = in.next().charAt(0);
            if (weight == 'B')
                blueCount++;
        
            addEdge(in.nextInt() - 1, in.nextInt() - 1, weight);
        }

        in.close();

        if (blueCount < blueEdges) {
            System.out.println("0");
            return;
        }

        if(hasBlueEdges()) 
            System.out.println("1");
        else 
            System.out.println("0");

    }

    public static boolean hasBlueEdges() 
    {
        boolean[] visited = new boolean[numNodes];
        return hasBlueEdges(visited, 0, 0);
    }

    private static boolean hasBlueEdges(boolean[] visited, int numBlues, int countedNodes) {

        if(numBlues == blueEdges && countedNodes == numNodes){
            return true;
        } else if (countedNodes == numNodes) {
            return false;
        }

        boolean possible = false;
        for (Edge e : edges) {
            if (visited[e.a]) continue;

            visited[e.a] = true;

            if (hasBlueEdges(visited, numBlues + (e.type == 'B' ? 1 : 0), countedNodes + 1)) 
                return true;

            visited[e.a] = false;
        }

        return possible;
    }


    private static void addEdge(int a, int b, char weight) {
        edges.add(new Edge(a, b, weight));
        edges.add(new Edge(b, a, weight));
    }


}


class Edge {

    int a;
    int b;
    char type;

    public Edge(int a, int b, char type) {
        this.a = a;
        this.b = b;
        this.type = type;
    }
}