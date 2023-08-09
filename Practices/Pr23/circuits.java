import java.util.*;

public class circuits {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(true) {
            int n = in.nextInt();
            if (n==0) break;
            double[][] grid = new double[26][26];

            for (int i = 0; i < n; i++) {
                int from = in.next().charAt(0)-'A', to = in.next().charAt(0)-'A';
                if(grid[from][to]>0){
                    grid[from][to] = 1/(1/grid[from][to] + 1/in.nextDouble());
                    grid[to][from] = grid[from][to];
                } else {
                    grid[from][to] = in.nextDouble();
                    grid[to][from] = grid[from][to];
                }
            }

            while (true) {
                boolean replaced = false;
                // from
                for (int i = 0; i < 26; i++) {

                    // to
                    jloop:for (int j = 1; j < 25; j++) {
                        if (grid[i][j] == 0) continue;

                        // check if the "to" goes to only one other edge
                        int ind = -1;
                        for (int k = 0; k < 26; k++) {
                            if (k==i) continue;
                            if (grid[j][k] > 0) {
                                // connects more than one!
                                if(ind!=-1) continue jloop;
                                ind = k;
                            }
                        }
                        if (ind==-1) continue jloop;

                        // System.out.println("removing: " + (char)(j+'a') + " to " + (char)(ind+'a'));
                        // System.out.println("adding to : " + (char)(i+'a'));
                        double dist = grid[i][j] + grid[j][ind];
                        Arrays.fill(grid[j], 0);
                        grid[ind][j] = 0;
                        grid[i][j] =0;

                        if (grid[i][ind] == 0){
                            grid[i][ind] = dist;
                            grid[ind][i] = dist;
                        }
                        else {
                            grid[i][ind] = 1/(1/grid[i][ind] + 1/dist);
                            grid[ind][i] = grid[i][ind];
                        }

                        replaced = true;
                    }
                }

                if(!replaced) break;
            }

            
            // for (double[] oneD : grid) {
            //     System.out.println(Arrays.toString(oneD));
            // }

            if (grid[0][25]>0&&noOtherEdge(grid)) {
                System.out.printf("%.3f\n", grid[0][25]);
            } else {
                System.out.println("-1.000");
            }

        }
    }

    private static boolean noOtherEdge(double[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (i == 0 && j == 25 || j == 0 && i == 25) {
                    continue;
                }
                if (grid[i][j] > 0) {
                    return false;
                }
            }
        }
        return true;
    }
}
