import java.util.Scanner;

public class counting {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int[] lefthand = new int[n + 1];
        lefthand[0] = 0;

        int[] righthand = new int[n + 1];
        righthand[n] = 0;

        int[] vals = new int[n];
        for (int i = 0; i < n; i++) {
            vals[i] = s.nextInt();
        }

        for (int i = 0; i < n + 1; i++) {
            lefthand[i + 1] = vals[0] + lefthand[i];
            righthand[n - i - 1] = vals[n - 1] + righthand[n - i - 2];
        }
        
    }
}
