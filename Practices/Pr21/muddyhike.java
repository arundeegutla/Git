import java.util.Arrays;
import java.util.Scanner;

public class muddyhike {
    public static int[][] D = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        int c = in.nextInt();
        int[][] grid = new int[r][c];
        boolean[][] visited = new boolean[r][c];
        int[][] memo = new int[r][c];
        for (int[] is : memo)
            Arrays.fill(is, -1);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = in.nextInt();
            }
        }

        int min = (int)1e9;
        for (int i = 0; i < r; i++) {
            memo[i][1] = go(i, 1, grid, memo, visited);
            memo[i][0] = Math.max(grid[i][0], memo[i][1]);
            min = Math.min(memo[i][0], min);
        }

        System.out.println(min);
    }

    private static int go(int row, int col, int[][] grid, int[][] memo, boolean[][] visited) {
        if (!inBounds(row, col, grid) || visited[row][col] || col == 0)
            return (int)1e9;

        if (col == grid[0].length - 1)
            return memo[row][col] = grid[row][col];

        if (memo[row][col] != -1)
            return memo[row][col];

        visited[row][col] = true;
        int min = (int)1e9;
        for (int[] d : D)
            min = Math.min(min, go(row+d[0], col+d[1], grid, memo, visited));
        visited[row][col] = false;

        return Math.max(min, grid[row][col]);
    }

    private static void printMemo(int[][] memo) {
        for (int[] is : memo)
            System.out.println(Arrays.toString(is));
        System.out.println();
    }

    private static boolean inBounds(int row, int col, int[][] grid) {
        return row >= 0 && row < grid.length && col >= 0 && col < grid[0].length;
    }
}


