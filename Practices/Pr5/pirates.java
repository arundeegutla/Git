import java.util.Scanner;

public class pirates {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numIslands = in.nextInt() * 2;

            int[][] grid = new int[numIslands][numIslands];

            for (int j = 0; j < numIslands; j++) {
                for (int j2 = 0; j2 < numIslands; j2++) {
                    grid[j][j2] = in.nextInt();
                }
            }
            
            int[] perm = new int[numIslands];
            boolean[] visited = new boolean[numIslands];

            System.out.println(getMinTime(grid, numIslands, perm, visited, 0));


        }

        in.close();

    }

    public static int getMinTime(int[][] grid, int numIslands, int[] perm, boolean[] visited, int k) {

        if (k == numIslands) {
            return 0;
        }

        int minTime = Integer.MAX_VALUE;

        int start = 0;
        int end = numIslands/2;

        if (k >= (numIslands/2)) {
            start = (int)(numIslands/2);
            end = numIslands;
        }


        for (int i = start; i < end; i++) {
            if (!visited[i]) {
                visited[i] = true;
                perm[k] = i;

                int time = 0;

                if (k == 0) {
                    time = getMinTime(grid, numIslands, perm, visited, k+1);
                } else {
                    time = grid[perm[k-1]][i] + getMinTime(grid, numIslands, perm, visited, k+1);
                }

                if(time < minTime) minTime = time;
                visited[i] = false;
            } 
        }

        return minTime;
    }
}
