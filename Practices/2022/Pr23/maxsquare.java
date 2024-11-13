import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.*;

public class maxsquare {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int n = in.nextInt();
            int m = in.nextInt();

            if(n==0&&m==0) break;

            int[][] grid = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) 
                    grid[i][j] = in.nextInt();

            int max = 0;
            int[][] memo = new int[n+1][m+1];
            for (int i = 1; i < n+1; i++)
                for (int j = 1; j < m+1; j++)
                    if (grid[i-1][j-1] == 1) 
                        max = Math.max(max, memo[i][j] = Math.min(Math.min(memo[i-1][j], memo[i][j-1]), memo[i-1][j-1]) + 1);

            System.out.println(max);

        }
    }
}
