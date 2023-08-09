import java.util.Scanner;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numBooks = in.nextInt();
        int low = in.nextInt();
        int high = in.nextInt();
        long[] prefix = new long[numBooks + 1];
        for (int i = 1; i <= numBooks; i++)
            prefix[i] = prefix[i-1] + in.nextInt();

        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for (int i = low; i <= high; i++) {
            for (int j = 0; j < i; j++) {
                int pos = 0;
                int start = j;
                while ((start - i) <= numBooks) {
                    long sum = prefix[Math.min(start, numBooks)] - prefix[Math.max(0, start-i)];
                    if (sum > 0)
                        pos++;
                    start += i;
                }
                max = Math.max(pos, max);
                min = Math.min(pos, min);
            }
        }
        System.out.println(min + " " + max);
    }
}
