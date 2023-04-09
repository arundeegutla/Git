import java.util.Arrays;
import java.util.Scanner;

public class wolf {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numIns = in.nextInt();

            int[] values = new int[numIns];
            double[] probs = new double[numIns];

            for (int j = 0; j < numIns; j++) {
                values[j] = in.nextInt();
            }

            for (int j = 0; j < numIns; j++) {
                probs[j] = in.nextDouble();
            }

            Arrays.sort(values);
            Arrays.sort(probs);

            double profit = 0;

            for (int j = 0; j < numIns; j++) {
                profit += (values[j] * probs[j]) - (values[j] * (1-probs[j]));
            }

            System.out.printf("%.2f", profit);
            System.out.println();
        }

        in.close();
    }
}
