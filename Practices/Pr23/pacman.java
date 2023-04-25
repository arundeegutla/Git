import java.util.*;
public class pacman {

    public static int[][] D = {{0, 1}, {1, 0}};
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int r = in.nextInt();
            int c = in.nextInt();

            in.next();
            int[][] grid = new int[r][c];
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) 
                    if((i==0&&j==0) || (i==r-1 && j == c-1)) continue;
                    else grid[i][j] = in.nextInt();

            in.next();

            int[][] memo = new int[r+1][c+1];
            for (int i = 1; i < r+1; i++)
                for (int j = 1; j < c+1; j++)
                    memo[i][j] = Math.max(memo[i-1][j], memo[i][j-1]) + grid[i-1][j-1];
            System.out.println(memo[r][c]);

        }
    }

}
