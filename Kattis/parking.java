import java.util.Arrays;
import java.util.Scanner;

public class parking {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

       for (int i = 0; i < numCases; i++) {

            int numSpots = in.nextInt();

            int[] spots = new int[numSpots];

            for (int j = 0; j < numSpots; j++)
                spots[j] = in.nextInt();

            Arrays.sort(spots);

            int middle = getMiddle(spots);

            System.out.println(getDistaceOfAll(spots, middle));
       } 

       in.close();

    }

    private static long getDistaceOfAll(int[] spots, int middle) {

        long dist = 0;
        int prev = middle;

        for (int i = 0; i < spots.length; i++) {
            dist += getDistance(spots[i], prev);
            prev = spots[i];
        }


        return dist + getDistance(middle, prev);
    }

    private static long getDistance(int thisOne, int prev) {
        return Math.abs(prev - thisOne);
    }

    private static int getMiddle(int[] spots) {
        return (spots[0] + spots[spots.length - 1]) / 2;
    }
}
