import java.util.ArrayList;
import java.util.Scanner;
import java.awt.Point;

/**
 * browniepoint1
 */
public class browniepoint1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPoints;
        while ((numPoints = in.nextInt()) != 0) {
            Point center = null;
            ArrayList<Point> brownies = new ArrayList<>();

            for (int i = 0; i < numPoints; i++) {
                Point thisPoint = new Point(in.nextInt(), in.nextInt());
                if (i == numPoints/2) {
                    center = thisPoint;
                    continue;
                }
                brownies.add(thisPoint);
            }

            int stan = 0;
            int olie = 0;
            for (Point point : brownies) {
                if (point.x == center.x || point.y == center.y)
                    continue;
                if ((point.x > center.x && point.y > center.y) || (point.x < center.x && point.y < center.y)) stan++;
                else olie++;
            }

            System.out.println(stan + " " + olie);
        }
    }
}