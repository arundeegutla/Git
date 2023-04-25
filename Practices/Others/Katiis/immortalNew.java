import java.util.Scanner;

public class immortalNew {
    public static int MOD = (int)1e9;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        while (numCases-->0)
            System.out.println(in.nextInt() + " " + fastFib(in.nextLong()));
    
    }

    private static long fastFib(long n) {
        return multiply(getNthMatrix(n), new long[][] {{1}, {0}})[1][0];
    }

    public static long[][] matrixExpo(long[][] base, long exp) {
		int n = base.length;
		if (exp == 0) return identity(n);
		if (exp%2 == 0) {
			long[][] sqrt = matrixExpo(base, exp/2);
			return multiply(sqrt, sqrt);
		}
		long[][] tmp = matrixExpo(base, exp-1);
		return multiply(tmp, base);
	}

    private static long[][] identity(int n) {
        long[][] m = new long[n][n];
        for (int i = 0; i < n; i++)
            m[i][i] = 1;
        return m;
    }

    private static long[][] getNthMatrix(long n) {
        return matrixExpo(new long[][] {{0, 1}, {1, 1}}, n);
    }

    public static long[][] multiply(long[][] A, long[][] B){

        int row1 = A.length, col1 = A[0].length;
        int row2 = B.length, col2 = B[0].length;

        if (row2 != col1) {
            Exception e = new Exception("cannot multiply Matrices " + row1 + "x" + col1 + " and " + row2 + "x" + col2);
            e.printStackTrace();
            System.exit(0);
            return null;
        }

        long C[][] = new long[row1][col2];
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < col2; j++)
                for (int k = 0; k < row2; k++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }
}

