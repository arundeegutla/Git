import java.util.Scanner;
import java.awt.Point;

/**
 * k
 */
public class k {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int x = in.nextInt();
        int y = in.nextInt();

        int n = in.nextInt();
        Point start = null;
        Point prev = null;
        while (n-- > 0) {
            Point here = new Point(in.nextInt(), in.nextInt());
            if (prev == null) {
                start = here;
                prev = here;
                continue;
            }

        }

    }
}