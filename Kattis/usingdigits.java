import java.util.*;
import java.awt.*;


/**
 * usingdigits
 */
public class usingdigits {
    public static int m;
    public static int n;
    public static char[][] grid;
    public static HashMap<Point, HashMap<String, Long>> memo;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        m = in.nextInt();
        n = in.nextInt();        
        String key = in.next();
        grid = new char[n][m];
        for (int i = 0; i < n; i++)
            grid[i] = in.next().toCharArray();
        memo = new HashMap<>();
        System.out.println(go(n-1, 0, key));
    }
    private static long go(int row, int col, String key) {
        if(row<0||row>=n||col<0||col>=m)
            return (long)1e10;
        int num = grid[row][col] - '0';
        if(row==0&&col==m-1)
            return num;

        Point p = new Point(row, col);
        HashMap<String, Long> map = memo.get(p);
        if(map!=null){
            Long ans = map.get(key);
            if(ans != null)
                return ans;
        }

        long val = go(row-1, col, key);
        val = Math.min(val, go(row, col+1, key));

        if(key.length() != 0) {
            int move = (key.charAt(0)-'0') + 1;
            val = Math.min(val, go(row, col+move, key.substring(1)));
            val = Math.min(val, go(row-move, col, key.substring(1)));
        }

        if(map == null) map = new HashMap<>();
        
        map.put(key, val+num);
        memo.put(p, map);
        return val+num;
    }
}
