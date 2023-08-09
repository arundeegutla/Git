import java.util.Arrays;
import java.util.Scanner;

/**
 * trainaddiction
 */
public class trainaddiction_arun {

    public static int MOD = (int)1e9 + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        while (numCases-->0) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] values = new int[k];
            int[] coeff = new int[51];
            for (int i = 0; i < values.length; i++) {
                values[i] = in.nextInt();
                coeff[values[i]]++;
            }

            // System.out.println();
            // System.out.println(n + " " + k);
            // System.out.println(Arrays.toString(values));
            // System.out.println("Actual+++" + getBruteForce(n, values));
            
            long[] dp = new long[51];
            Arrays.fill(dp, -1);
            for (int i = 1; i <= 50; i++)
                go(i, values, dp);
            
            long[][] base = new long[50][1];
		    for (int i = 49; i >= 0; i--) 
                base[i][0] = dp[50-i];

            boolean[][] changed = new boolean[50][50];
            long[][] matrix = new long[50][50];
            for (int i=0; i<50; i++) matrix[0][i] = coeff[i+1];
            for (int i=1; i<50; i++) matrix[i][i-1] = 1;


            long answer = n < 50 ? base[50-n][0] : multiply(matrixExpo(matrix, n-50, changed), base, null)[0][0];

            if (answer > 0)
                System.out.println(answer);
            else if (answer == 0 && changed[0][0])
                System.out.println(0);
            else
                System.out.println("IMPOSSIBLE");
        }
    }

    private static void printMatrix(long[][] matrix, int maxNum) {
        for (int i = 0; i < maxNum; i++) {
            for (int j = 0; j < maxNum; j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
    }

    private static long getBruteForce(int n, int[] values) {
        long[] base1 = new long[n+1];
        Arrays.fill(base1, -1);
        return go(n, values, base1);
    }

    private static long go(int need, int[] values, long[] memo) {
        if (need == 0) return 1;
        if (need < 0) return 0;

        if (memo[need] != -1)
            return memo[need];

        long tot = 0;
        for (int i : values) {
            tot += go(need-i, values, memo);
            tot %= MOD;
        }
        return memo[need] = tot;
    }


    public static long[][] matrixExpo(long[][] m, int exp, boolean[][] changed) {
		if (exp == 0) return identity(m.length);
		if (exp%2 == 0) {
			long[][] tmp = matrixExpo(m, exp/2, changed);
			return multiply(tmp, tmp, changed);
		}
		long[][] tmp = matrixExpo(m, exp-1, changed);
		return multiply(tmp, m, changed);
	}

    private static long[][] identity(int n) {
        long[][] m = new long[n][n];
        for (int i = 0; i < n; i++)
            m[i][i] = 1;
        return m;
    }

    public static long[][] multiply(long[][] A, long[][] B, boolean[][] changed) {
        int row1 = A.length, col1 = A[0].length;
        int row2 = B.length, col2 = B[0].length;

        long C[][] = new long[row1][col2];

        for (int i = 0; i < row1; i++)
            for (int j = 0; j < col2; j++)
                for (int k = 0; k < row2; k++) {
                    C[i][j] = (C[i][j] + (A[i][k] * B[k][j]));
                    if (changed != null && C[i][j] > 0)
                        changed[i][j] = true;
                    C[i][j] %= MOD;
                }

        return C;
    }
}