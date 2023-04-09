import java.util.HashMap;
import java.util.Scanner;
import java.awt.Point;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numSodas = in.nextInt();
        int numLiters = in.nextInt();

        int[] sodaPrices = new int[numSodas];

        for (int i = 0; i < sodaPrices.length; i++) {
            sodaPrices[i] = in.nextInt();
        }

        HashMap<Point, Long> map = new HashMap<>();
        System.out.println(getMin(sodaPrices, 0, numLiters, map));
    }

    private static long getMin(int[] sodaPrices, int at, int numLiters) {

        HashMap<Integer, Integer>[] arr = new HashMap<Integer, Integer>[2];

        for (int j = 0; j <= numLiters; j++)
            map.put(new Point(sodaPrices.length, j), Long.MAX_VALUE);

        for (int i = sodaPrices.length - 1; i >= 0 ; i--) {
            for (int j = 1; j <= numLiters; j++)
                map.put(new Point(i, j), Math.min(sodaPrices[i] + (j - (1<<i) <= 0 ? 0 : map.get(new Point(i, j - (1<<i)))), map.get(new Point(i+1, j))));
        }

        return map.get(new Point(at, numLiters));
    }
}
