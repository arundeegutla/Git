// Liam Keliher, 2023
//
// Solution for Kattis problem "Train Addiction" (trainaddiction)
//
// The number of trains of length N, T(N), is given by the recurrence
//        T(N) = C_1*T(N-1) + C_2*T(N-2) + ... + C_50*T(N-50)
// where C_i is the number of different train cars of length i,
// and the initial values are T(0) = 1 and T(i) = 0 for i < 0.
//
// Because we want T(N) for large values of N, we embed the recurrence
// in a matrix and then use square-and-multiply to compute the Nth power
// of this matrix.
//
// To save time, we only apply a mod operation during matrix multiplication
// when absolutely necessary, i.e., when adding a term of the form a*b might
// overflow a long (see use of constant MOD_THRESHOLD in matrixMultiply()).


import java.io.*;

public class train {
    private static final long MODULUS = 1_000_000_007;
    private static final long MOD_THRESHOLD = Long.MAX_VALUE - (MODULUS - 1)*(MODULUS - 1);
    private static final int MAX_CAR_LENGTH = 50;

    private static final long WRAPPED_AROUND_TO_ZERO = -1;
    //---------------------------------------------------------------
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder(15*numCases);
        for (int c = 0; c < numCases; c++) {
            String[] tokens = br.readLine().split(" ");
            int N = Integer.parseInt(tokens[0]);
            int K = Integer.parseInt(tokens[1]);
            int[] histogram = new int[MAX_CAR_LENGTH];   // uses 0-based indexing
            int maxCarLen = 0;
            for (int index = 0; index < K; index++) {
                int carLen = Integer.parseInt(tokens[index + 2]);
                histogram[carLen - 1]++;   // note 0-based indexing
                if (carLen > maxCarLen) {
                    maxCarLen = carLen;
                } // if
            } // for index

            // Embed the recurrence in a matrix
            long[][] M = new long[maxCarLen][maxCarLen];
            for (int j = 0; j < maxCarLen; j++) {
                M[0][j] = histogram[j];
            } // for j
            for (int i = 1; i < maxCarLen; i++) {    // NOTE: start at 1
                M[i][i - 1] = 1;
            } // for i

            // Begin with M^0, the identity matrix
            long[][] Mpower = new long[maxCarLen][maxCarLen];
            for (int i = 0; i < maxCarLen; i++) {
                Mpower[i][i] = 1;
            } // for i

            while (N > 0) {
                if (N % 2 == 1) {
                    Mpower = matrixMultiply(Mpower, M);
                } // if
                M = matrixMultiply(M, M);
                N /= 2;
            } // while N

            long answer = Mpower[0][0];
            if (answer == 0) {
                sb.append("IMPOSSIBLE\n");
            } // if
            else if (answer == WRAPPED_AROUND_TO_ZERO) {
                sb.append("0\n");
            } // else if
            else {
                sb.append(answer).append('\n');
            } // else
        } // for c
        System.out.print(sb);
    } // main(String[])
    //---------------------------------------------------------------
    // Multiplies two square matrices (of the same size) and returns the product
    private static long[][] matrixMultiply(long[][] M1, long[][] M2) {
        int n = M1.length;
        long[][] result = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                boolean includesPositiveMultipleOfModulus = false;
                long entry = 0;
                for (int k = 0; k < n; k++) {
                    long term1 = M1[i][k];
                    long term2 = M2[k][j];

                    // Normal (nonzero) case
                    if (term1 > 0 && term2 > 0) {
                        entry += term1 * term2;
                    } // if

                    // Current term is a positive integer multiple of MODULUS
                    else if ((term1 == WRAPPED_AROUND_TO_ZERO && term2 != 0) || (term2 == WRAPPED_AROUND_TO_ZERO && term1 != 0)) {
                        includesPositiveMultipleOfModulus = true;
                    } // else if

                    if (entry > MOD_THRESHOLD) {   // see comment at top about MOD_THRESHOLD
                        entry %= MODULUS;
                        includesPositiveMultipleOfModulus = true;
                    } // if
                } // for k
                if (entry >= MODULUS) {   // ensure each final entry is < MODULUS
                    entry %= MODULUS;
                    includesPositiveMultipleOfModulus = true;
                } // if
                if (entry == 0 && includesPositiveMultipleOfModulus) {
                    entry = WRAPPED_AROUND_TO_ZERO;
                } // if
                result[i][j] = entry;
            } // for j
        } // for i
        return result;
    } // matrixMultiply(long[][],long[][])
    //---------------------------------------------------------------
} // class TrainAddictionKeliher

