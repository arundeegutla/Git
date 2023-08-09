import java.util.Scanner;

public class jump_backtracking {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numBlocks = in.nextInt();

            int[] blocks = new int[numBlocks];

            for (int j = 0; j < numBlocks; j++) {
                blocks[j] = in.nextInt();
            }

            int maxUP = in.nextInt();
            int maxDown = in.nextInt();

            int[] perm = new int[numBlocks];
            boolean[] used = new boolean[numBlocks];

            System.out.println(getMaxArragments(blocks, perm, used, maxUP, maxDown, 0));
        }
        in.close();
    }

    public static int getMaxArragments(int[] blocks, int[] perm, boolean[] used, int maxUP, int maxDown, int k) {

        if (k == blocks.length) {
            return 1;
        }

        int numArragements = 0;

        for (int i = 0; i < blocks.length; i++) {

            if (!used[i] && (k == 0 || valid(blocks[perm[k-1]], blocks[i], maxDown, maxUP))) {
                used[i] = true;
                perm[k] = i;
                numArragements += getMaxArragments(blocks, perm, used, maxUP, maxDown, k+1);
                used[i] = false;
            }
        }

        return numArragements; 
    }

    public static boolean valid(int i, int j, int maxDown, int maxUP) {

        int diff = i - j;

        if (diff > 0) {
            return diff <= maxDown;
        }
        return -diff <= maxUP;
    }
}
