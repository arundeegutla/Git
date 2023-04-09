import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class jump {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numBlocks = in.nextInt();

            int[] blocks = new int[numBlocks];

            for (int j = 0; j < numBlocks; j++)
                blocks[j] = in.nextInt();

            int maxUP = in.nextInt();
            int maxDown = in.nextInt();

            System.out.println(solve(blocks, maxUP, maxDown));
        }
        in.close();
    }


    private static int solve(int[] blocks, int maxUP, int maxDown) {

        int[][] memo = new int[1<<blocks.length][blocks.length];
        for (int[] is : memo)
            Arrays.fill(is, -1);

        int total = 0;
        for (int i = 0; i < blocks.length; i++) 
            total += tsp((1<<blocks.length) - 1, i, memo, blocks, maxUP, maxDown);
        return total;
    }


    private static int tsp(int mask, int next, int[][] memo, int[] blocks, int maxUP, int maxDown) {
        if (memo[mask][next] != -1)
            return memo[mask][next];

        if (Integer.bitCount(mask) == 1)
        {
            System.out.println(Integer.toBinaryString(mask) + " " + Integer.toBinaryString(next));
            return 1;
        }
        
        int oldmask = mask - (1<<next);

        int total = 0;
        for (int i = 0; i < blocks.length; i++) {
            if ((oldmask & (1<<i)) == 0 || !isValid(blocks[i], blocks[next], maxDown, maxUP))
                continue;

            total += tsp(oldmask, i, memo, blocks, maxUP, maxDown);
        }
        return memo[mask][next] = total;
    }


    public static boolean isValid(int i, int j, int maxDown, int maxUP) {

        int diff = i - j;

        if (diff > 0)
            return diff <= maxDown;

        return -diff <= maxUP;
    }
}
