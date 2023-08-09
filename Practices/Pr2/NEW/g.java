import java.util.Scanner;

/**
 * g
 */
public class g {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String rain = in.nextLine();

        int[] blueSum = new int[rain.length() + 1];
        int[] redSum = new int[rain.length() + 1];

        for (int i = 0; i < rain.length(); i++) {
            blueSum[i + 1] = blueSum[i];
            redSum[i + 1] = redSum[i];

            if (rain.charAt(i) == 'B')
                blueSum[i + 1]++;
            else
                redSum[i + 1]++;
        }

        int left = 0;
        int right = 0;
        int best = 0;

        for (int i = 1; i < blueSum.length; i++) {
            for (int j = i; j < blueSum.length; j++) {
                if (Math.abs((blueSum[j] - blueSum[i-1]) - (redSum[j] - redSum[i-1])) > best) {
                    left = i;
                    right = j;
                    best = Math.abs((blueSum[j] - blueSum[i-1]) - (redSum[j] - redSum[i-1]));
                }
            }
        } 

        System.out.println(left + " " + right);

    }
}

// BBRRBRRBRB