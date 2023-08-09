import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.awt.Point;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashSet<Point> hittings = new HashSet<>();

        int knightCount = 0;
        
        loop : for (int i = 0; i < 5; i++) {
            String word = in.nextLine();
            for (int j = 0; j < 5; j++) {
                if (word.charAt(j) == 'k') {
                    Point thisKnight = new Point(i, j);

                    if (hittings.contains(thisKnight))
                        break loop;

                    hittings.addAll(getMoves(thisKnight));
                    knightCount++;

                }
            }
        }

        if (knightCount == 9)
            System.out.println("valid");
        else
            System.out.println("invalid");

    }

    private static ArrayList<Point> getMoves(Point thisKnight) {

        ArrayList<Point> points = new ArrayList<>();
        int[][] moves = {{-2, 1}, {-2, -1}, {-1, -2,}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        for (int[] move : moves)
            if (thisKnight.x + move[0] >= 0 && thisKnight.x + move[0] <= 4 && thisKnight.y + move[1] >= 0 && thisKnight.y + move[1] <= 4)
                points.add(new Point(thisKnight.x + move[0], thisKnight.y + move[1]));

        return points;
    }
}
