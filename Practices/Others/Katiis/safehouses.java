import java.util.Scanner;

/**
 * safehouses
 */
public class safehouses {

    // Valid movements for floodfill.
    public static int[] DX = {-1,0,0,1};
    public static int[] DY = {0,-1,1,0};


    public static char[][] grid;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int size = in.nextInt();
        in.nextLine();

        grid = new char[size][size];

        for (int i = 0; i < size; i++) {
            String line = in.nextLine();
            for (int j = 0; j < size; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        int maxDistance = Integer.MIN_VALUE;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == 'S')
                {
                    boolean[][] visited = new boolean[size][size];
                    int distance = getNearestHouseDistance(i, j, i, j, grid, visited);

                    if (distance > maxDistance){
                        maxDistance = distance;
                    }
                }
            }
        }

        System.out.println(maxDistance);
        in.close();

    }

    public static int getNearestHouseDistance(int startX, int startY, int i, int j, char[][] grid, boolean[][] visited) {

        if (i < 0 || j < 0 || i >= grid.length || j >= grid.length) {
            return Integer.MAX_VALUE;
        }

        if (visited[i][j]) {
            return Integer.MAX_VALUE;
        }


        if (grid[i][j] == 'H') {
            return Math.abs(i - startX) + Math.abs(j - startY);
        }

        visited[i][j] = true;
        

        int minDistance = Integer.MAX_VALUE;
        
        for (int k = 0; k < DX.length; k++) {


            int distance = getNearestHouseDistance(startX, startY, i+DX[k], j+DY[k], grid, visited);
            if (distance < minDistance) {
                minDistance = distance;
            }

        }
        
        return minDistance;
    }
}