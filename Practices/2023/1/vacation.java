import java.util.*;
import java.awt.*;

public class vacation {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        for (int i = 1; i <= numCases; i++) {
            double ans = solve(in);
            System.out.printf("Vacation #%d:\n", i);
            if (ans == -1)
                System.out.println("Jimmy should plan this vacation a different day.");
            else
                System.out.printf("Jimmy can finish all of the rides in %.3f seconds.\n", ans);
            System.out.println();
        }
    }

    private static double solve(Scanner in) {
        int numRides = in.nextInt();
        int blocledPaths = in.nextInt();
        Point[] rides = new Point[numRides];
        for (int i = 0; i < rides.length; i++)
            rides[i] = new Point(in.nextInt(), in.nextInt());
        
        HashSet<Integer>[] blocked = new HashSet[numRides];
        for (int i = 0; i < blocked.length; i++)
            blocked[i] = new HashSet<>();

        for (int i = 0; i < blocledPaths; i++) {
            int from = in.nextInt()-1, to = in.nextInt()-1;
            blocked[from].add(to);
            blocked[to].add(from);
        }

        int[] perm = new int[numRides];
        boolean[] used = new boolean[numRides];
        double ans = go(0, perm, used, rides, blocked);
        return ans == 1e9 ? -1 : ans;
    }

    private static double go(int at, int[] perm, boolean[] used, Point[] rides, HashSet<Integer>[] blocked) {
        if (at == perm.length)
            return 0;

        double min = 1e9;
        for (int i = 0; i < perm.length; i++) {
            if (!used[i] && (at == 0 || !blocked[perm[at-1]].contains(i))) {
                used[i] = true;
                perm[at] = i;
                double path = rides[i].distance(at != 0 ? rides[perm[at-1]] : new Point(0,0)) + go(at+1, perm, used, rides, blocked);
                min = Math.min(min, path+120);
                used[i] = false;
            }
        }
        return min;
    }
}