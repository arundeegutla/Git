import java.util.*;
import java.awt.*;

public class muddyhike {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] D = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = in.nextInt();
        
        HashMap<Point, Integer> map = new HashMap<>();
        Queue<Point> q = new ArrayDeque<>();

        int max = (int)1e9;
        for (int i = 0; i < n; i++) {
            map.put(new Point(i, 0), grid[i][0]);
            q.add(new Point(i, 0));
        }

        loop:while (!q.isEmpty()) {
            Point here = q.poll();
            int maxHere = map.get(here);
            if (here.y == m - 1) {
                max = Math.min(max, maxHere);
                continue loop;
            }
            for (int[] d : D) { 
                int row = here.x + d[0];
                int col = here.y + d[1];
                if (!(row>=0&&row<n&&col>=0&&col<m))
                    continue;
                int maxNext = Math.max(maxHere, grid[row][col]);
                Point p = new Point(row, col);
                if (!map.containsKey(p) || maxNext < map.get(p)) {
                    map.put(p, maxNext);
                    q.add(p);
                }
            }
        }

        System.out.println(max);

    }
}
