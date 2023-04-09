import java.util.Scanner;

public class oddq {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int len = in.nextInt();
            int numQ = in.nextInt();

            int[] preSum = new int[len + 1];
            for (int i = 1; i <= len; i++) {
                preSum[i] = preSum[i-1] + in.nextInt();
            }
            
            for (int i = 0; i < numQ; i++) {
                int start = in.nextInt();
                int end = in.nextInt();
                long k = in.nextInt();
                // System.out.println(end - start + 1);
                // System.out.println(preSum[len] + " - " + (preSum[end] - preSum[start-1]) + " + " + (k*(end-start + 1)));
                long sum = preSum[len] - (preSum[end] - preSum[start-1]) + (k*(end-start + 1));

                if (sum%2!=0) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }
    }
}
