import java.util.Scanner;

public class greedypolygons {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        while (t-- > 0) {
            int n = s.nextInt(), l = s.nextInt(), d = s.nextInt(), g = s.nextInt();

            Point[] points = new Point[n];
            points[0] = new Point(0, 0);

            double currAngle = 0;
            for (int i = 1; i < n; i++) {
                points[i] = new Point(points[i - 1].x + (l * Math.cos(currAngle)), points[i - 1].y + (l * Math.sin(currAngle)));
                currAngle += Math.PI - ((n - 2) * Math.PI) / (double) n;
            }

            double innerArea = shoelace(points);
            System.out.println(innerArea + Math.PI * (d * g) * (d * g) + (n * d * g * l));
        }
    }

    static double shoelace(Point[] points) {
        double l = 0, r = 0;

        for (int i = 0; i < points.length; i++) {
            l += points[i].x * points[(i + 1) % points.length].y;
            r += points[i].y * points[(i + 1) % points.length].x;
        }

        return Math.abs(l - r) / 2;
    }
}

class Point {
    double x, y;
    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}
