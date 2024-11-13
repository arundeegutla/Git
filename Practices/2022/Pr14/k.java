// its not matrix rref :(
import java.util.Scanner;
import java.awt.Point;

public class k {

    public static Point p;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        outer : while (n-- > 0) {

            int legType1 = in.nextInt();
            int armType1 = in.nextInt();

            int legType2 = in.nextInt();
            int armType2 = in.nextInt();

            int legTotal = in.nextInt();
            int armTotal = in.nextInt();
            
            int finalX = -1;
            int finalY = -1;
            boolean found = false;
            for (int x = 1; legType1 * x < legTotal; x++) {
                double y = (double)(legTotal - (legType1 * x)) / legType2;
                if (y == (int)y && (armType1 * x) + (armType2 * y) == armTotal) {
                    if (found) {
                        System.out.println("?");
                        continue outer;
                    }
                    finalX = x;
                    finalY = (int)y;
                    found = true;
                }
            }

            if (found)
                System.out.println(finalX + " " + finalY);
            else
                System.out.println("?");
        }
    }

}