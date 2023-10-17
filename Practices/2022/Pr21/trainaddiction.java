import java.util.Arrays;
import java.util.Scanner;
/**
 * trainaddiction
 */
public class trainaddiction {
	public static int MOD = (int)1e9 + 7;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		loop:while (numCases-->0) {

			int n = in.nextInt();
			int k = in.nextInt();
			int[] values = new int[k];
			int[] coeff = new int[51];

			for (int i = 0; i < values.length; i++) {
				values[i] = in.nextInt();
				coeff[values[i]]++;
			}

			long[] dp = new long[50];
			Arrays.fill(dp, -1); dp[0] = 1;
			for (int i = 0; i < 50; i++) go(i, values, dp);


			long[][] matrix = new long[50][50];
			for (int i=0; i<50; i++) matrix[49][49-i] = coeff[i+1];
			for (int i=1; i<50; i++) matrix[i-1][i] = 1;
			matrix = matrixExpo(matrix, n);

			long ans = 0;
			boolean modded = false;
			for (int i = 0; i < matrix.length; i++) {
				ans += (matrix[0][i] * dp[i]) % MOD;
				if (ans >= MOD) {
					ans %= MOD; 
					modded = true;
				}
			}

			if (ans == 0 && !modded) {
				System.out.println("IMPOSSIBLE");
				continue loop;
			}

			System.out.println(ans);
		}
	}

	public static long[][] matrixExpo(long[][] m, int exp) {
		if (exp == 0) return identity(m.length);
		if (exp%2 == 0) {
			long[][] tmp = matrixExpo(m, exp/2);
			return multiply(tmp, tmp);
		}
		long[][] tmp = matrixExpo(m, exp-1);
		return multiply(tmp, m);
	}

	private static long[][] identity(int n) {
		long[][] m = new long[n][n];
		for (int i = 0; i < n; i++) m[i][i] = 1;
		return m;
	}

	public static long[][] multiply(long[][] A, long[][] B) {
		int row1 = A.length, col1 = A[0].length;
		int row2 = B.length, col2 = B[0].length;
		long C[][] = new long[row1][col2];
		for (int i = 0; i < row1; i++)
			for (int j = 0; j < col2; j++)
				for (int k = 0; k < row2; k++)
					C[i][j] = (C[i][j] += (A[i][k] * B[k][j]) % MOD) % MOD;
		return C;
	}

	private static long go(int need, int[] values, long[] memo) {
		if (need == 0) return 1;
		if (need < 0) return 0;
		if (memo[need] != -1) return memo[need];

		long tot = 0;
		for (int i : values) {
			tot += go(need-i, values, memo);
			tot %= MOD;
		}

		return memo[need] = tot;
	}
}