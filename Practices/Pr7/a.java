import java.util.Arrays;
import java.util.Scanner;

public class a {
     public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numTrees = in.nextInt();
        int numStarts = in.nextInt();
        int numCables = in.nextInt();

        Treehouse[] trees = new Treehouse[numTrees];
        double[][] distances = new double[numTrees][numTrees];

        for (int i = 0; i < numTrees; i++)
            trees[i] = new Treehouse(in.nextDouble(), in.nextDouble());


        for (int i = 0; i < numTrees; i++) {
            for (int j = 0; j < numTrees; j++) {

                if(i < numStarts && j < numStarts) 
                    distances[i][j] = 0;
                else 
                    distances[i][j] = getDistance(trees[i], trees[j]);
            }
        }

        for (int i = 0; i < numCables; i++) {

            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;

            distances[a][b] = 0;
            distances[b][a] = 0;
        }

        // printGrid(distances);

        System.out.printf("%.3f\n", getMinimumCableLength(distances, numTrees));


        in.close();

     }



    private static void printGrid(double[][] distances) {
        for (int i = 0; i < distances.length; i++) {
            for (int j = 0; j < distances.length; j++) {
                System.out.print((int)distances[i][j] + " ");
            }
            System.out.println();
        }
    }



    public static double getDistance(Treehouse a, Treehouse b) {
        return Math.sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    }

  
    public static double getMinimumCableLength(double[][] graph, int numTrees)
    {

        int parent[] = new int[numTrees];
        double minimums[] = new double[numTrees];
        boolean visited[] = new boolean[numTrees];
    
        Arrays.fill(minimums, Double.MAX_VALUE);
        
 
        minimums[0] = 0;
        int connectedTrees = 1;


        while(connectedTrees < numTrees)
        {


            int currNode = getNodeWithLowestEdge(visited, minimums);

            visited[currNode] = true;
            connectedTrees++;
            
            // System.out.println("VISITING " + currNode);

            for (int i = 0; i < numTrees; i++)
                if (!visited[i] && graph[currNode][i] < minimums[i]) {
                    parent[i] = currNode;
                    minimums[i] = graph[currNode][i];
                }
            

        }

        // System.out.println(Arrays.toString(parent));

 
        double result = 0;
        for (int i = 1; i < numTrees; i++){
            result += graph[i][parent[i]];
        }

        return result;
    }



    private static int getNodeWithLowestEdge(boolean[] visited, double[] minimums) {

        double min = Double.MAX_VALUE;
        int node = 0;

        for (int i = 0; i < visited.length; i++){
            if (!visited[i] && minimums[i] < min) {
                min = minimums[i];
                node = i;
            }
        }

        return node;
    }
 
}

class Treehouse{
    double x;
    double y;

    public Treehouse(double x, double y){
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "{" + x + ", " + y + "}";
    }
}
