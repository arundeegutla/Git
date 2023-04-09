import java.util.Scanner;
import java.awt.geom.Line2D;

/**
 * brocard
 */
public class brocard {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        while (numCases-- > 0) {
            in.nextInt();
            double ax = in.nextDouble();
            double ay = in.nextDouble();
            double bx = in.nextDouble();
            double by = in.nextDouble();
            double cx = in.nextDouble();
            double cy = in.nextDouble();

            Line2D ab = new Line2D.Double(ax, ay, bx, by);
            Line2D ac = new Line2D.Double(ax, ay, cx, cy);
            Line2D bc = new Line2D.Double(bx, by, cx, cy);

        }
    }
}