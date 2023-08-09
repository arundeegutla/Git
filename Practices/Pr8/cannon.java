import java.util.ArrayList;
import java.util.Scanner;

public class cannon {

    final int distps = 5;
    final int candist = 50;
    final int cantime = 2;
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int currX = s.nextInt(), currY = s.nextInt();
        int destX = s.nextInt(), destY = s.nextInt();
        int cannons = s.nextInt();

        ArrayList<C> cs = new ArrayList<C>();
        for (int i = 0; i < cannons; i++) {
            cs.add(new C(s.nextInt(), s.nextInt()));
        }

        double totalTime = 0;
        for (int i = 0; i < cannons; i++) {
            int closestDist = Integer.MAX_VALUE;
        }
    }

    static double dist(int x1, int y1, int x2, int y2) {
        return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
    }
}

class C {
    int x;
    int y;

    C(int x, int y) {
        this.x = x;
        this.y = y;
    }
}