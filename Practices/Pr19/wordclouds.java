import java.util.Arrays;
import java.util.Scanner;

/**
 * wordclouds
 */
public class wordclouds {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numClouds = in.nextInt();
        int max = in.nextInt();

        int[] widths = new int[numClouds];
        int[] heights = new int[numClouds];
        for (int i = 0; i < numClouds; i++) {
            widths[i] = in.nextInt();
            heights[i] = in.nextInt();
        }

        int[] memo = new int[numClouds+1];
        Arrays.fill(memo, -1);
        System.out.println(go(0, max, widths, heights, memo));
    }

    private static int go(int at, int max, int[] widths, int[] heights, int[] memo) {

        if (at == heights.length)
            return 0;
        if (memo[at] != -1)
            return memo[at];

        int width = 0;
        int maxHeight = 0;
        int minTotal = (int)1e9;

        for (int i = at; i < heights.length; i++) {
            width += widths[i];
            maxHeight = Math.max(maxHeight, heights[i]);
            if(width <= max)
                minTotal = Math.min(minTotal, maxHeight + go(i+1, max, widths, heights, memo));
        }

        return memo[at] = minTotal;
    }
}