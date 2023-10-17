import java.util.Scanner;
import java.awt.Point;

public class s {
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int numPhotos = in.nextInt();
        
        Point[] pictures = new Point[numPhotos];

        for (int i = 0; i < pictures.length; i++)
            pictures[i] = new Point(in.nextInt(), in.nextInt());

        int max = 0;
        for (int i = 0; i + 1 < pictures.length; i++)
            max = Math.max(max, getSpeed(pictures[i], pictures[i+1]));

        System.out.println(max);
    }

    private static int getSpeed(Point point, Point point2) {
        int top = point2.y - point.y;
        int bottom = point2.x - point.x;
        return top/bottom;
    }
}
