import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.awt.Point;

public class bouncyball {
    public static HashMap<String, Integer> map;
    public static HashMap<Point, Integer> pMap;
    public static int[][] D = {{1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
    public static int numBounces;
    public static void main(String[] args) {
        map = new HashMap<>();
        map.put("DL", 0);
        map.put("DR", 1);
        map.put("UL", 2);
        map.put("UR", 3);

        pMap = new HashMap<>();
        pMap.put(new Point(1, -1), 0);
        pMap.put(new Point(1, 1), 1);
        pMap.put(new Point(-1, -1), 2);
        pMap.put(new Point(-1, 1), 3);


        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        while (numCases-->0) {
            int n = in.nextInt(), m = in.nextInt();
            Point start = new Point(in.nextInt(), in.nextInt());
            Point end = new Point(in.nextInt(), in.nextInt());
            int dir = map.get(in.next());
            numBounces = 0;

            Cell[][] grid = new Cell[n+1][m+1];
            for (int i = 0; i < n+1; i++)
                for (int j = 0; j < m+1; j++)
                    grid[i][j] = new Cell(i, j);

            System.out.println(getBounces(start.x, start.y, dir, grid, end));

        }
    }
    private static int getBounces(int x, int y, int dir, Cell[][] grid, Point end) {

        while (x!=end.x || y!=end.y) {
            grid[x][y].directions |= dir;

            Point d = new Point(D[dir][0], D[dir][1]);
            int newDir = getDir(x+d.x, y+d.y, grid, d);
            if ((grid[x+d.x][y+d.y].directions & dir) != 0)
                return -1;

            x = x+d.x;
            y = y+d.y;
            dir = newDir;
        }
        
        return numBounces;
    }

    private static int getDir(int i, int j, Cell[][] grid, Point d) {
        boolean bounced = false;
        if (!(i >= 1 && i < grid.length)) {
            d.setLocation(-d.x, d.y);
            bounced = true;
        }
        if (!(j >= 1 && j < grid[0].length)) {
            d.setLocation(d.x, -d.y);
            bounced = true;
        }
        numBounces += bounced ? 1 : 0;
        return pMap.get(d);
    }
}

class Cell {

    int row;
    int col;
    int directions;

    Cell(int row, int col) {
        this.row = row;
        this.col = col;
        directions = 0;
    }
}


class FastScanner {
    BufferedReader br; StringTokenizer st;
            public FastScanner() {
                try {
                    br = new BufferedReader(new InputStreamReader(System.in));
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e){e.printStackTrace();}
            }
            public String next() {
                if (st.hasMoreTokens()) return st.nextToken();
                try {st = new StringTokenizer(br.readLine());}
                catch (Exception e) {e.printStackTrace();}
                return st.nextToken();
            }
            public short nextShort() {return Short.parseShort(next());}
            public int nextInt() {return Integer.parseInt(next());}
            public long nextLong() {return Long.parseLong(next());}
            public double nextDouble() {return Double.parseDouble(next());}
            public String nextLine() {
                String line = "";
                if(st.hasMoreTokens()) 
    line = st.nextToken();
                else 
    try {return br.readLine();}catch(IOException e){e.printStackTrace();}
                while(st.hasMoreTokens()) line += " "+st.nextToken();
                return line;
            }
    }
    