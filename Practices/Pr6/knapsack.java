import java.util.Scanner;

public class knapsack {

	public static void main(String[] args) {

		// Read in a single case from input.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int[] weights = new int[n];
		int[] values = new int[n];
		for (int i=0; i<n; i++) {
			weights[i] = stdin.nextInt();
			values[i] = stdin.nextInt();
		}
		int capacity = stdin.nextInt();

		// dp[i] will store max value of knapsack with capacity i.
		int[] dp = new int[capacity+1];

		// go through each item.
		for (int i=0; i<n; i++) {
            // oneCopy
			//for (int w=capacity; w>=weights[i]; w--)
			for (int w=weights[i]; w<=capacity; w++)
				dp[w] = Math.max(dp[w], dp[w-weights[i]] + values[i] );
		}
	}
}