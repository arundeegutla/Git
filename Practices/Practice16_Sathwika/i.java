import java.util.*;

public class i {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int w = in.nextInt();
        int s = in.nextInt();

        int x = in.nextInt();
        int y = in.nextInt();

        int[][] workpieces = new int[w][x];
        int[][] steps = new int[s][x];

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < x; j++)
            {
                workpieces[i][j] = in.nextInt();
            }
        }

        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < x; j++)
            {
                steps[i][j] = in.nextInt();
            }
        }
        
        // final step (max gap)
        int[] finalStep = new int[x];
        for (int ind = 0; ind < x; ind++)
        {
            int max = 0;
            for (int[] curS: steps)
            {
                max = (curS[ind] > max) ? curS[ind] : max;
            }

            finalStep[ind] = max;
        }

        // System.out.println(Arrays.toString(finalStep));
        // for each W run through all steps
        for (int eachW = 0; eachW < w; eachW++)
        {
            // all steps
            int[] curW = workpieces[eachW];
            for (int go = 0; go < x; go++)
            {
                // cur ind possible
                int check = y - curW[go];
                if (finalStep[go] > check)
                {
                    curW[go] = (y - finalStep[go]);
                }
            }
            // System.out.println("CurW: " + Arrays.toString(curW));
            for (int out = 0; out < x; out++)
            {
                System.out.print(curW[out] + " ");
            }
            System.out.println();
        }
     
    }
}
