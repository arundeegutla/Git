import java.util.Arrays;
import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        float[] probs = new float[6];
        float ogexpected = 0;
        float tot = 0;
        for (int i = 0; i < probs.length; i++) {
            probs[i] = in.nextFloat() * 6;
            tot += probs[i];
            ogexpected += probs[i]*(i+1);
        }

        System.out.println(Arrays.toString(probs) + "\n" + ogexpected + " " + Math.round(tot));
    }
}
