import java.util.Scanner;
import java.awt.Point;

public class f {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        Point goat = new Point(in.nextInt(), in.nextInt());

        Point point1 = new Point(in.nextInt(), in.nextInt());
        Point point2 = new Point(in.nextInt(), in.nextInt());

        Point closestPoint = new Point();

        if (point1.getX() < goat.getX() && point2.getX() > goat.getX()) {
            closestPoint.x = goat.x;
            closestPoint.y = Math.abs(goat.y - point1.y) < Math.abs(goat.y - point2.y) ? point1.y : point2.y;

        } else if (point1.getY() < goat.getY() && point2.getY() > goat.getY()) {
            closestPoint.y = goat.y;
            closestPoint.x = Math.abs(goat.x - point1.x) < Math.abs(goat.x - point2.x) ? point1.x : point2.x;
        } else {
            closestPoint.y = Math.abs(goat.y - point1.y) < Math.abs(goat.y - point2.y) ? point1.y : point2.y;
            closestPoint.x = Math.abs(goat.x - point1.x) < Math.abs(goat.x - point2.x) ? point1.x : point2.x;
        }

        System.out.println(goat.distance(closestPoint));

        in.close();
    }
}
