import java.sql.Array;
import java.util.Arrays;
import java.util.Scanner;

public class trainaddiction_arun {
    public static int MOD = (int)1e9 + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {

            int N = in.nextInt();
            int K = in.nextInt();
            int[] freq = new int[51];
            for (int i = 0; i < K; i++) {
                freq[in.nextInt()]++;
            }

            System.out.println(Arrays.toString(freq));
            int[][] memo = new int[51][N+1];
            for (int[] is : memo)
                Arrays.fill(is, -1);

            int total = go(1, N, freq, memo);
            if (total == 0) {
                System.out.println("IMPOSSIBLE");
            } else {
                System.out.println(total);
            }
        }
    }

    private static int go(int at, int N, int[] freq, int[][] memo) {
        if (N == 0) 
            return 1;

        if(at == freq.length || N < 0)
            return 0;

        if (memo[at][N] != -1)
            return memo[at][N];

        if (freq[at] == 0)
            return go(at+1, N, freq, memo);

        int max = 0;
        for (int i = 0; N-(at*i) >= 0; i++)
            max += go(at+1, N-(at*i), freq, memo);
    
        return memo[at][N] = max % MOD;
    }
}
