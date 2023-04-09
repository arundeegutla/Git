import java.util.Scanner;

class schoolspirit {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = s.nextInt();
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += (arr[i] * Math.pow((double) 4 / 5, i));
        }
        double total = 0;
        for (int i = 0; i < n; i++) {
            double curr = 0;
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    curr += (arr[j] * Math.pow((double) 4 / 5, num));
                    num++;
                }
            }
            total += curr;
        }
        System.out.println(res / 5);
        System.out.println(total / (5 * n));
    }
}