import java.util.HashMap;
import java.util.Scanner;
import java.awt.geom.*;
import java.awt.*;

/**
 * c
 */
public class c {

    public static Scanner in = new Scanner(System.in);
    public static HashMap<Integer, Point> map = new HashMap<>();

    public static void solve() {
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
        Line2D ab = new Line2D.Double(map.get(a), map.get(b));
        Line2D cd = new Line2D.Double(map.get(c), map.get(d));
        if (ab.intersectsLine(cd)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static void main(String[] args) {

        map.put(12, new Point(0, 3));
        map.put(1, new Point(1, 2));
        map.put(2, new Point(2, 1));
        map.put(3, new Point(3, 0));
        map.put(4, new Point(2, -1));
        map.put(5, new Point(1, -2));
        map.put(6, new Point(0, -3));
        map.put(7, new Point(-1, -2));
        map.put(8, new Point(-2, -1));
        map.put(9, new Point(-3, 0));
        map.put(10, new Point(-2, 1));
        map.put(11, new Point(-1, 2));

        int t = in.nextInt();
        while (t-- > 0) {
            solve();
        }

    }
}