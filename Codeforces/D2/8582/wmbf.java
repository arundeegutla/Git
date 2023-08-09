import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;
import java.awt.Point;

public class wmbf {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
            
            HashMap<Point, Integer> map = new HashMap<>();
            Queue<Point> q = new ArrayDeque<>();
            map.put(new Point(a, b), 0);
            q.add(new Point(a, b));

            while (!q.isEmpty()) {
                Point p = q.poll();
                int dist = map.get(p);
                if (p.equals(new Point(c, d))) {
                    break;
                }

                if (!map.containsKey(new Point(p.x-1, p.y)) || map.get(new Point(p.x-1, p.y)) > dist + 1) {
                    map.put(new Point(p.x-1, p.y), dist + 1);
                    q.add(new Point(p.x-1, p.y));
                }

                if (!map.containsKey(new Point(p.x + 1, p.y + 1)) || map.get(new Point(p.x + 1, p.y + 1)) > dist + 1) {
                    map.put(new Point(p.x+1, p.y + 1), dist + 1);
                    q.add(new Point(p.x+1, p.y + 1));
                }                
            }

            System.out.println(map.containsKey(new Point(c, d)) ? map.get(new Point(c, d)) : -1);
        }
    }
}
