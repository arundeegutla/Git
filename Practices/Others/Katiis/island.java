import java.util.Arrays;
import java.util.Scanner;

public class island {
     public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int cases = 0; cases < numCases; cases++) {


            int numIslands = in.nextInt();

            Island[] islands = new Island[numIslands];
            double[][] distances = new double[numIslands][numIslands];

            for (int i = 0; i < numIslands; i++) {
                islands[i] = new Island(in.nextDouble(), in.nextDouble());
            }


            for (int i = 0; i < numIslands; i++) {
                for (int j = 0; j < numIslands; j++) {
                    distances[i][j] = getDistance(islands[i], islands[j]);
                }
            }

            System.out.println(getMinimumLength(distances, numIslands));

        }

        in.close();

     }



    public static double getDistance(Island a, Island b) {
        return Math.sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    }

  
    public static double getMinimumLength(double[][] graph, int numIslands)
    {

        int parent[] = new int[numIslands];
        double key[] = new double[numIslands];
        boolean visited[] = new boolean[numIslands];
    
        for (int i = 0; i < numIslands; i++) {
            key[i] = Double.MAX_VALUE;
        }
 
        key[0] = 0;
        parent[0] = -1; 

        System.out.println(Arrays.toString(key));


        for (int count = 0; count < numIslands - 1; count++) {

            double min = Double.MAX_VALUE;
            int u = -1;
    
            for (int v = 0; v < numIslands; v++){
                if (!visited[v] && key[v] < min) {
                    min = key[v];
                    u = v;
                }
            }
                
            visited[u] = true;
            
            System.out.println("VISITING " + u);

            for (int v = 0; v < numIslands; v++)
                if (!visited[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            
            System.out.println(Arrays.toString(key));
            
        }
 
        double result = 0;
        for (int i = 1; i < numIslands; i++){
            result += graph[i][parent[i]];
        }

        return result;
    }
 
}

class Island{
    double x;
    double y;

    public Island(double x, double y){
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "{" + x + ", " + y + "}";
    }
}
