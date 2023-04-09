import java.util.Arrays;
import java.util.Scanner;

public class jacuzzi {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numSides = in.nextInt();


            int[] sides = new int[numSides];

            for (int j = 0; j < numSides; j++) {
                sides[j] = in.nextInt();
            }

            Arrays.sort(sides);

            int total = 0;
            for (int j = 0; j < numSides-1; j++) {
                total += sides[j];
            }

            if (total <= sides[numSides-1]) {
                System.out.println("Jacuzzi #" + (i+1) + ": NO");
            } else 
                System.out.println("Jacuzzi #" + (i+1) + ": YES");

        }

        in.close();
    }
}
