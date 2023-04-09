import java.sql.Array;
import java.util.Arrays;
import java.util.Scanner;

public class genius {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int K = in.nextInt();
        int T = in.nextInt();
        int P = in.nextInt();
        int Q = in.nextInt();
        int X1 = in.nextInt();

        int[] predicted = getPredicted(X1, P, Q, T);

        for (int i = 0; i < T; i++) {
            double w1 = in.nextInt();
            double w2 = in.nextInt();
            double w3 = in.nextInt();
            double w4 = in.nextInt();

            double winnerProb = getWinnerProb(predicted[i], w1, w2, w3, w4);

        }

        System.out.println(Arrays.toString(predicted));
    }

    private static double getWinnerProb(int aw, double w1, double w2, double w3, double w4) {
        if (aw == 0) {
            return (w1/(w1+w2))/((w1/(w1+w2))+(w3/w3+w4)) * (w1/(w1+w2))/((w1/(w1+w2))+(w4/w4+w3));
        } else if (aw == 1) {
            return (w1/(w1+w2))/((w1/(w1+w2))+(w3/w3+w4)) * (w1/(w1+w2))/((w1/(w1+w2))+(w4/w4+w3));
            
        } else if (aw == 2) {
            return (w1/(w1+w2))/((w1/(w1+w2))+(w3/w3+w4)) * (w1/(w1+w2))/((w1/(w1+w2))+(w4/w4+w3));
            
        } else if (aw == 3) {
            return (w1/(w1+w2))/((w1/(w1+w2))+(w3/w3+w4)) * (w1/(w1+w2))/((w1/(w1+w2))+(w4/w4+w3));
        }
        return 0;
    }

    private static int[] getPredicted(int x1, int p, int q, int t) {
        int[] predicted = new int[t];
        int[] actualpredicted = new int[t];
        predicted[0] = x1;
        actualpredicted[0] = x1%4;
        for (int i = 1; i < predicted.length; i++) {
            predicted[i] = (predicted[i-1] * p) % q;
            actualpredicted[i] = predicted[i] % 4;
        }
        return actualpredicted;
    }
}
