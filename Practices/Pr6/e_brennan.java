import java.util.Scanner;

public class e_brennan {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = s.nextInt();

        int res = n - 1;
        for (int i = 0; i < n; i++) {
            int startheight = arr[i];
            int currMax = -1;

            for (int j = i + 2; j < n; j++) {
                for (int k = i; k < j; k++) {
                    currMax = Math.max(currMax, arr[k]);
                }
            }

            if (startheight > currMax) res++;
        }

        System.out.println(res);
    }
}
