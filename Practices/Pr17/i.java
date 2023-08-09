import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
import java.awt.Point;

public class i {
    public static int[][] d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int SIZE = in.nextInt();
        in.nextLine();

        Cell[][] grid = new Cell[SIZE][SIZE];
        for (int i = 0; i < grid.length; i++) {
            char[] arr = in.nextLine().toCharArray();
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] == '.')
                    grid[i][j] = new Cell(-1);
            }
        }
        
        grid[0][0].dist = 0;
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(0, 0));

        while (!q.isEmpty()) {
            // printGrid(grid);
            Point p = q.poll();
            int row = p.x;
            int col = p.y;
            Cell c = grid[row][col];

            for (int i = 0; i < d.length; i++) {
                int newR = row + d[i][0], newC = col + d[i][1];
                if (!isValid(newR, newC, SIZE, grid))
                    continue;
                
                Cell newCell = grid[newR][newC];
                int newDistance = c.dist + (c.direction[i] ? 0 : 1);

                if (newCell.dist == -1 || newCell.dist > newDistance || (newCell.dist == newDistance && !newCell.direction[i])) {
                    if (newCell.dist > newDistance)
                        newCell.clear();
                
                    newCell.direction[i] = true;
                    newCell.dist = newDistance;
                    q.add(new Point(newR, newC));
                }
            }
        }

        // printGrid(grid);
        
        System.out.println(grid[SIZE - 1][SIZE - 1].dist);

    }

    private static void printGrid(Cell[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (grid[i][j] == null || grid[i][j].dist == -1) {
                    System.out.print("- ");
                }else
                    System.out.print(grid[i][j].dist + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static boolean isValid(int newRow, int newCol, int SIZE, Cell[][] grid) {
        if(newRow < 0 || newCol < 0 || newRow >= SIZE || newCol >= SIZE || grid[newRow][newCol] == null)
            return false;
        return true;
    }
}

class Cell {
    int dist;
    boolean[] direction;
    Cell(int dist)
    {
        this.dist = dist;
        direction = new boolean[4];
    }
    public void clear()
    {
        for (int i = 0; i < direction.length; i++)
            direction[i] = false;
    }
}